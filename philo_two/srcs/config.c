/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:47:00 by triou             #+#    #+#             */
/*   Updated: 2020/08/02 21:47:01 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int	error(const char *e)
{
	ft_putstr_fd(e, 2);
	return (EXIT_FAILURE);
}

int			config(t_config *conf, int ac, char **av)
{
	int	n;

	if (ac < 5)
	{
		ft_putstr_fd(USAGE, 2);
		return (EXIT_FAILURE);
	}
	if ((n = ft_atos(av[1])) < 0)
		return (error(PARAMS));
	conf->number_of_philosopher = n;
	if ((conf->time_to_die = ft_atos(av[2])) < 0)
		return (error(PARAMS));
	if ((conf->time_to_eat = ft_atos(av[3])) < 0)
		return (error(PARAMS));
	if ((conf->time_to_sleep = ft_atos(av[4])) < 0)
		return (error(PARAMS));
	conf->number_of_time_each_philosophers_must_eat = (ac == 6)
		? ft_atos(av[5]) : -1;
	conf->is_finished = false;
	conf->wait = 0;
	return (EXIT_SUCCESS);
}
