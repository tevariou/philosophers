/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:47:31 by triou             #+#    #+#             */
/*   Updated: 2020/08/02 21:47:33 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"
#include <unistd.h>

static void	update(
		t_philosopher *philosopher,
		const char *status,
		struct timeval time
)
{
	if (!ft_strcmp("died", status))
	{
		sem_wait(philosopher->conf->print);
		philosopher->conf->is_finished = true;
		sem_post(philosopher->conf->print);
	}
	if (!ft_strcmp("is eating", status))
	{
		sem_wait(philosopher->eating);
		philosopher->state.last_eating = time;
		sem_post(philosopher->eating);
	}
}

int			print_status(const char *status, size_t number, t_philosopher *philosopher)
{
	struct timeval	time;
	char			str[53];

	gettimeofday(&time, NULL);
	sem_wait(philosopher->conf->print);
	if (philosopher->conf->is_finished)
	{
		sem_post(philosopher->conf->print);
		return (EXIT_FAILURE);
	}
	sem_post(philosopher->conf->print);
	update(philosopher, status, time);
	ft_memset(str, 0, 53);
	ft_putnbr(str, timeval_to_msec(time));
	ft_append(str, " ");
	ft_putnbr(str, number);
	ft_append(str, " ");
	ft_append(str, status);
	ft_append(str, "\n");
	ft_putstr_fd(str, 1);
	return (EXIT_SUCCESS);
}
