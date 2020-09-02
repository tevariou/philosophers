/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:47:07 by triou             #+#    #+#             */
/*   Updated: 2020/08/02 21:47:08 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static bool	is_turn(t_philosopher *philosopher, size_t n, size_t total)
{
	bool	ret;

	ret = false;
	sem_wait(philosopher->conf->print);
	if (philosopher->conf->wait == n)
	{
		philosopher->conf->wait += 1;
		if (philosopher->conf->wait == total)
			philosopher->conf->wait = 0;
		ret = true;
	}
	sem_post(philosopher->conf->print);
	return (ret);
}

int			thinking(t_philosopher *philosopher)
{
	size_t	n;
	size_t	total;
	int		time_to_wait;

	n = philosopher->number;
	total = philosopher->conf->number_of_philosopher;
	if (print_status("is thinking", n + 1, philosopher))
		return (EXIT_FAILURE);
	time_to_wait = philosopher->conf->time_to_sleep - 10;
	if (total % 2 == 0 || time_to_wait <= 0)
		return (EXIT_SUCCESS);
	if (is_turn(philosopher, n, total))
		ft_sleep(time_to_wait);
	return (EXIT_SUCCESS);
}
