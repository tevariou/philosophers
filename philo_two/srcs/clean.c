/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:46:54 by triou             #+#    #+#             */
/*   Updated: 2020/08/02 21:46:55 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	clean(t_philosopher *philo_array, t_config *conf)
{
	sem_close(conf->print);
	sem_close(conf->forks);
	free(philo_array);
}
