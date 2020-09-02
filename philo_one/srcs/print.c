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

int	print_status(const char *status, size_t number, t_config *conf)
{
	struct timeval	time;
	char			str[53];

	gettimeofday(&time, NULL);
	if (conf->is_finished)
		return (EXIT_FAILURE);
	if (!ft_strcmp("died", status))
		conf->is_finished = true;
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
