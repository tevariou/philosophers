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

void	print_status(const char *status, size_t number, t_config *conf)
{
	char			str[53];
	struct timeval	time;

	sem_wait(conf->print);
	gettimeofday(&time, NULL);
	ft_memset(str, 0, 53);
	ft_putnbr(str, timeval_to_msec(time));
	ft_append(str, " ");
	ft_putnbr(str, number);
	ft_append(str, " ");
	ft_append(str, status);
	ft_append(str, "\n");
	ft_putstr_fd(str, 1);
	sem_post(conf->print);
}
