/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:45:15 by triou             #+#    #+#             */
/*   Updated: 2020/08/02 21:45:16 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include "unistd.h"
#include <string.h>

static void	update(t_config *conf, const char *status)
{
	if (!ft_strcmp("died", status))
	{
		pthread_mutex_lock(&conf->mutex);
		conf->is_finished = true;
		pthread_mutex_unlock(&conf->mutex);
	}
}

int			print_status(const char *status, size_t number, t_config *conf)
{
	struct timeval	time;
	char			str[53];

	gettimeofday(&time, NULL);
	pthread_mutex_lock(&conf->mutex);
	if (conf->is_finished)
	{
		pthread_mutex_unlock(&conf->mutex);
		return (EXIT_FAILURE);
	}
	pthread_mutex_unlock(&conf->mutex);
	update(conf, status);
	memset(str, 0, 53);
	ft_putnbr(str, timeval_to_msec(time));
	ft_append(str, " ");
	ft_putnbr(str, number);
	ft_append(str, " ");
	ft_append(str, status);
	ft_append(str, "\n");
	ft_putstr_fd(str, 1);
	return (EXIT_SUCCESS);
}
