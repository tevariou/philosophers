/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:49:15 by triou             #+#    #+#             */
/*   Updated: 2020/08/02 21:49:16 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <string.h>

void	print_status(const char *status, size_t number, t_config *conf)
{
	char			str[34];
	struct timeval	time;

	gettimeofday(&time, NULL);
	sem_wait(conf->print);
	memset(str, 0, 34);
	ft_putnbr(str, timeval_to_msec(time));
	ft_append(str, " ");
	ft_putnbr(str, number);
	ft_append(str, " ");
	ft_append(str, status);
	ft_append(str, "\n");
	ft_putstr_fd(str, 1);
	if (ft_strcmp(status, "died"))
		sem_post(conf->print);
}
