/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:47:07 by triou             #+#    #+#             */
/*   Updated: 2020/08/02 21:47:08 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static bool	is_alive(t_philosopher *philosopher, size_t number)
{
	struct timeval	time;
	struct timeval	last_eating;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;

	gettimeofday(&time, NULL);
	sem_wait(philosopher->eating);
	last_eating = philosopher->state.last_eating;
	sem_post(philosopher->eating);
	time_to_die = philosopher->conf->time_to_die;
	time_to_eat = philosopher->conf->time_to_eat;
	if (last_eating.tv_sec
		&& timeval_cmp(time, timeval_add(last_eating, time_to_eat)) <= 0)
		return (true);
	sem_wait(philosopher->eating);
	last_eating = philosopher->state.last_eating;
	if (timeval_cmp(time, timeval_add(last_eating, time_to_die)) > 0)
	{
		print_status("died", number + 1, philosopher);
		sem_post(philosopher->eating);
		return (false);
	}
	sem_post(philosopher->eating);
	return (true);
}

void		*monitor_run(void *arg)
{
	t_philosopher	*philosopher_array;
	t_config		*conf;
	size_t			i;
	int				n;
	size_t			counter;

	philosopher_array = (t_philosopher *)arg;
	conf = philosopher_array[0].conf;
	n = conf->number_of_time_each_philosophers_must_eat;
	while (1)
	{
		counter = 0;
		i = 0;
		while (i < conf->number_of_philosopher)
		{
			if (!is_alive(philosopher_array + i, i))
				return (NULL);
			counter += (philosopher_array[i].state.counter == n) ? 1 : 0;
			sem_post(philosopher_array[i].eating);
			i++;
		}
		if (counter == conf->number_of_philosopher)
			break ;
	}
	return (NULL);
}
