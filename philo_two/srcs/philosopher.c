/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:47:15 by triou             #+#    #+#             */
/*   Updated: 2020/08/02 21:47:16 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"
#include <unistd.h>

static int	eating(t_philosopher *philosopher)
{
	struct timeval	time;
	size_t			n;
	int				ret;

	n = philosopher->number;
	gettimeofday(&time, NULL);
	sem_wait(philosopher->eating);
	if (print_status("is eating", n + 1, philosopher))
	{
		sem_post(philosopher->conf->forks);
		sem_post(philosopher->conf->forks);
		sem_post(philosopher->eating);
		return (EXIT_FAILURE);
	}
	sem_post(philosopher->eating);
	ft_sleep(philosopher->conf->time_to_eat);
	sem_post(philosopher->conf->forks);
	sem_post(philosopher->conf->forks);
	n = philosopher->conf->number_of_time_each_philosophers_must_eat;
	sem_wait(philosopher->eating);
	ret = (++philosopher->state.counter == (int)n) ? 1 : 0;
	sem_post(philosopher->eating);
	return (ret);
}

static int	sleeping(t_philosopher *philosopher)
{
	size_t	n;

	n = philosopher->number;
	if (print_status("is sleeping", n + 1, philosopher))
		return (EXIT_FAILURE);
	ft_sleep(philosopher->conf->time_to_sleep);
	return (EXIT_SUCCESS);
}

static int	take_fork(t_philosopher *philosopher)
{
	size_t	n;

	n = philosopher->number;
	sem_wait(philosopher->conf->forks);
	if (print_status("has taken a fork", n + 1, philosopher))
	{
		sem_post(philosopher->conf->forks);
		return (EXIT_FAILURE);
	}
	sem_wait(philosopher->conf->forks);
	if (print_status("has taken a fork", n + 1, philosopher))
	{
		sem_post(philosopher->conf->forks);
		sem_post(philosopher->conf->forks);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void		*even_philosopher_run(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	gettimeofday(&philosopher->state.last_eating, NULL);
	while (1)
	{
		if (thinking(philosopher))
			return (NULL);
		if (take_fork(philosopher))
			return (NULL);
		if (eating(philosopher))
			return (NULL);
		if (sleeping(philosopher))
			return (NULL);
	}
}

void		*odd_philosopher_run(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	gettimeofday(&philosopher->state.last_eating, NULL);
	while (1)
	{
		if (sleeping(philosopher))
			return (NULL);
		if (thinking(philosopher))
			return (NULL);
		if (take_fork(philosopher))
			return (NULL);
		if (eating(philosopher))
			return (NULL);
	}
}
