/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:45:05 by triou             #+#    #+#             */
/*   Updated: 2020/08/02 21:45:06 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	eating(
	t_philosopher *philosopher,
	pthread_mutex_t *first,
	pthread_mutex_t *second
)
{
	struct timeval	time;
	size_t			n;
	int				ret;

	n = philosopher->number;
	pthread_mutex_lock(&philosopher->eating);
	gettimeofday(&time, NULL);
	if (print_status("is eating", n + 1, philosopher->conf))
	{
		pthread_mutex_unlock(&philosopher->eating);
		return (EXIT_FAILURE);
	}
	philosopher->state.last_eating = time;
	pthread_mutex_unlock(&philosopher->eating);
	ft_sleep(philosopher->conf->time_to_eat);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
	n = philosopher->conf->number_of_time_each_philosophers_must_eat;
	pthread_mutex_lock(&philosopher->state.mutex);
	ret = (++philosopher->state.counter == (int)n) ? EXIT_FAILURE : EXIT_SUCCESS;
	pthread_mutex_unlock(&philosopher->state.mutex);
	return (ret);
}

static int	sleeping(t_philosopher *philosopher)
{
	size_t	n;

	n = philosopher->number;
	if (print_status("is sleeping", n + 1, philosopher->conf))
		return (EXIT_FAILURE);
	ft_sleep(philosopher->conf->time_to_sleep);
	return (EXIT_SUCCESS);
}

static int	take_fork(
	t_philosopher *philosopher,
	pthread_mutex_t *first,
	pthread_mutex_t *second
)
{
	size_t	n;

	n = philosopher->number;
	pthread_mutex_lock(first);
	if (print_status("has taken a fork", n + 1, philosopher->conf))
	{
		pthread_mutex_unlock(first);
		return (EXIT_FAILURE);
	}
	pthread_mutex_lock(second);
	if (print_status("has taken a fork", n + 1, philosopher->conf))
	{
		pthread_mutex_unlock(second);
		pthread_mutex_unlock(first);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void		*even_philosopher_run(void *arg)
{
	t_philosopher	*philosopher;
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;
	size_t			n;

	philosopher = (t_philosopher *)arg;
	gettimeofday(&philosopher->state.last_eating, NULL);
	n = philosopher->number;
	first = (philosopher->left > philosopher->right)
		? philosopher->right : philosopher->left;
	second = (philosopher->left > philosopher->right)
		? philosopher->left : philosopher->right;
	while (1)
	{
		if (print_status("is thinking", n + 1, philosopher->conf))
			return (NULL);
		if (take_fork(philosopher, first, second))
			return (NULL);
		if (eating(philosopher, first, second))
			return (NULL);
		if (sleeping(philosopher))
			return (NULL);
	}
}

void		*odd_philosopher_run(void *arg)
{
	t_philosopher	*philosopher;
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;
	size_t			n;

	philosopher = (t_philosopher *)arg;
	gettimeofday(&philosopher->state.last_eating, NULL);
	n = philosopher->number;
	first = (philosopher->left > philosopher->right)
		? philosopher->right : philosopher->left;
	second = (philosopher->left > philosopher->right)
		? philosopher->left : philosopher->right;
	while (1)
	{
		if (sleeping(philosopher))
			return (NULL);
		if (print_status("is thinking", n + 1, philosopher->conf))
			return (NULL);
		if (take_fork(philosopher, first, second))
			return (NULL);
		if (eating(philosopher, first, second))
			return (NULL);
	}
}
