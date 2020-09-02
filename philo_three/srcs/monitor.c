/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:48:51 by triou             #+#    #+#             */
/*   Updated: 2020/08/02 21:48:52 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <string.h>

static void	is_alive(t_philosopher *philosopher)
{
	struct timeval	time;
	struct timeval	last_eating;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;

	gettimeofday(&time, NULL);
	sem_wait(philosopher->eating);
	last_eating = philosopher->state.last_eating;
	time_to_die = philosopher->conf->time_to_die;
	time_to_eat = philosopher->conf->time_to_eat;
	if (last_eating.tv_sec
		&& timeval_cmp(time, timeval_add(last_eating, time_to_eat)) > 0
		&& timeval_cmp(time, timeval_add(last_eating, time_to_die)) > 0)
	{
		print_status("died", philosopher->number + 1);
		sem_post(philosopher->eating);
		exit(0);
	}
	sem_post(philosopher->eating);
}

void		*monitor_run(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	while (1)
		is_alive(philosopher);
}
