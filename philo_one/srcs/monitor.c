/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:42:11 by triou             #+#    #+#             */
/*   Updated: 2020/08/01 18:51:28 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <unistd.h>

static bool	is_alive(t_philosopher *philosopher, size_t number)
{
	struct timeval	time;
	struct timeval	last_eating;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;

	gettimeofday(&time, NULL);
	pthread_mutex_lock(&philosopher->eating);
	last_eating = philosopher->state.last_eating;
	pthread_mutex_unlock(&philosopher->eating);
	time_to_die = philosopher->conf->time_to_die;
	time_to_eat = philosopher->conf->time_to_eat;
	if (last_eating.tv_sec
		|| timeval_cmp(time, timeval_add(last_eating, time_to_eat)) <= 0)
		return (true);
	pthread_mutex_lock(&philosopher->eating);
	last_eating = philosopher->state.last_eating;
	if (timeval_cmp(time, timeval_add(last_eating, time_to_die)) > 0)
	{
		print_status("died", number + 1, philosopher->conf);
		pthread_mutex_unlock(&philosopher->eating);
		return (false);
	}
	pthread_mutex_unlock(&philosopher->eating);
	return (true);
}

static int	increment(t_philosopher *philosopher, int n)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&philosopher->state.mutex);
	if (philosopher->state.counter == n)
		ret += 1;
	pthread_mutex_unlock(&philosopher->state.mutex);
	return (ret);
}

void		*monitor_run(void *arg)
{
	t_philosopher	*philosopher_array;
	t_config		*conf;
	size_t			i;
	size_t			counter;
	int				n;

	philosopher_array = (t_philosopher *)arg;
	conf = philosopher_array[0].conf;
	n = conf->number_of_time_each_philosophers_must_eat;
	while (1)
	{
		i = 0;
		counter = 0;
		while (i < conf->number_of_philosopher)
		{
			if (!is_alive(philosopher_array + i, i))
				return (NULL);
			counter += increment(philosopher_array + i, n);
			i++;
		}
		if (counter == conf->number_of_philosopher)
			break ;
	}
	return (NULL);
}
