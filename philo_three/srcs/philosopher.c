/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:48:58 by triou             #+#    #+#             */
/*   Updated: 2020/08/02 21:49:00 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <unistd.h>

static void	eating(t_philosopher *philosopher)
{
	struct timeval	time;
	size_t			n;

	n = philosopher->number;
	gettimeofday(&time, NULL);
	print_status("BEFORE eating", n + 1, philosopher->conf);
	sem_wait(philosopher->eating);
	print_status("is eating", n + 1, philosopher->conf);
	philosopher->state.last_eating = time;
	sem_post(philosopher->eating);
	ft_sleep(philosopher->conf->time_to_eat);
	sem_post(philosopher->conf->forks);
	sem_post(philosopher->conf->forks);
	n = philosopher->conf->number_of_time_each_philosophers_must_eat;
	if (++philosopher->state.counter == (int)n)
		exit(0);
}

static void	sleeping(t_philosopher *philosopher)
{
	size_t	n;

	n = philosopher->number;
	print_status("is sleeping", n + 1, philosopher->conf);
	ft_sleep(philosopher->conf->time_to_sleep);
}

static void	take_fork(t_philosopher *philosopher)
{
	size_t	n;

	n = philosopher->number;
	sem_wait(philosopher->conf->forks);
	print_status("has taken a fork", n + 1, philosopher->conf);
	sem_wait(philosopher->conf->forks);
	print_status("has taken a fork", n + 1, philosopher->conf);
}

void		even_philosopher_run(t_philosopher *philosopher)
{
	size_t	n;

	gettimeofday(&philosopher->state.last_eating, NULL);
	n = philosopher->number;
	while (1)
	{
		print_status("is thinking", n + 1, philosopher->conf);
		take_fork(philosopher);
		eating(philosopher);
		sleeping(philosopher);
	}
}

void		odd_philosopher_run(t_philosopher *philosopher)
{
	size_t	n;

	gettimeofday(&philosopher->state.last_eating, NULL);
	n = philosopher->number;
	while (1)
	{
		sleeping(philosopher);
		print_status("is thinking", n + 1, philosopher->conf);
		take_fork(philosopher);
		eating(philosopher);
	}
}
