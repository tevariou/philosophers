/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:48:38 by triou             #+#    #+#             */
/*   Updated: 2020/08/02 21:48:40 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <signal.h>

void	clean(
	t_philosopher *philo_array,
	pid_t *pid_array,
	t_config *conf
)
{
	size_t	i;

	i = 0;
	while (i < conf->number_of_philosopher)
	{
        if (!kill(pid_array[i], 0))
			kill(pid_array[i], SIGTERM);
        sem_close(philo_array[i].eating);
        i++;
	}
	free(pid_array);
	sem_close(conf->print);
	sem_close(conf->forks);
	free(philo_array);
}
