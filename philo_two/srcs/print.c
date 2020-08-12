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

int	print_status(const char *status, size_t number, t_philosopher *philosopher)
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
	if (!ft_strcmp("died", status))
		philosopher->conf->is_finished = true;
	if (!ft_strcmp("is eating", status))
		philosopher->state.last_eating = time;
	ft_memset(str, 0, 53);
	ft_putnbr(str, timeval_to_msec(time));
	ft_append(str, " ");
	ft_putnbr(str, number);
	ft_append(str, " ");
	ft_append(str, status);
	ft_append(str, "\n");
	ft_putstr_fd(str, 1);
	sem_post(philosopher->conf->print);
	return (EXIT_SUCCESS);
}
