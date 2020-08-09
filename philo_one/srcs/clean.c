/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:36:50 by triou             #+#    #+#             */
/*   Updated: 2020/08/01 18:41:02 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	clean(
		t_philosopher *philosopher_array,
		pthread_mutex_t *fork_array,
		pthread_mutex_t *mutex,
		size_t n
)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&philosopher_array[i].eating);
		pthread_mutex_destroy(&fork_array[i]);
		i++;
	}
	pthread_mutex_destroy(mutex);
	free(philosopher_array);
	free(fork_array);
}
