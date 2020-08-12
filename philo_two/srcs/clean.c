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
	size_t i;

	sem_close(conf->print);
	sem_close(conf->forks);
	i = 0;
	while (i < conf->number_of_philosopher)
	{
		sem_close(philo_array[i].eating);
		i++;
	}
	free(philo_array);
}
