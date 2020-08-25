/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:44:53 by triou             #+#    #+#             */
/*   Updated: 2020/08/02 21:44:54 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <unistd.h>
#include <string.h>

static int	init(
	t_philosopher *philosopher_array,
	pthread_mutex_t *fork_array,
	t_config *main_conf
)
{
	size_t	i;
	size_t	n;

	n = main_conf->number_of_philosopher;
	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(&fork_array[i], NULL)
			|| pthread_mutex_init(&philosopher_array[i].eating, NULL)
			|| pthread_mutex_init(&philosopher_array[i].state.mutex, NULL))
		{
			clean(philosopher_array, fork_array, &main_conf->mutex, i + 1);
			return (EXIT_FAILURE);
		}
		philosopher_array[i].conf = main_conf;
		philosopher_array[i].left = fork_array + i;
		philosopher_array[i].right = i
				? fork_array + i - 1 : fork_array + n - 1;
		philosopher_array[i].number = i;
		philosopher_array[i].state.counter = 0;
		philosopher_array[i].state.last_eating.tv_sec = 0;
		philosopher_array[i].state.last_eating.tv_usec = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	pwait(
	t_philosopher *philo_array,
	t_config *conf,
	pthread_t *monitor
)
{
	size_t	i;

	i = 0;
	while (i < conf->number_of_philosopher)
	{
		pthread_join(philo_array[i].thread, NULL);
		i++;
	}
	pthread_join(*monitor, NULL);
}

static int	run(
	t_philosopher *philo_array,
	t_config *conf
)
{
	size_t		i;
	size_t		n;
	pthread_t	monitor;
	void		*(*f)(void *);

	n = conf->number_of_philosopher;
	i = 0;
	while (i < n)
	{
		f = (i % 2 == 0) ? &odd_philosopher_run : &even_philosopher_run;
		if (pthread_create(&philo_array[i].thread, NULL, f, philo_array + i))
			return (EXIT_FAILURE);
		usleep(500);
		i++;
	}
	if (pthread_create(&monitor, NULL, &monitor_run, philo_array))
		return (EXIT_FAILURE);
	pwait(philo_array, conf, &monitor);
	return (EXIT_SUCCESS);
}

static int	alloc(
	pthread_mutex_t **fork_array,
	t_philosopher **philosopher_array,
	t_config *conf
)
{
	size_t	size;

	size = sizeof(pthread_mutex_t) * conf->number_of_philosopher;
	if (!(*fork_array = (pthread_mutex_t *)malloc(size)))
	{
		pthread_mutex_destroy(&conf->mutex);
		return (EXIT_FAILURE);
	}
	memset(*fork_array, 0, size);
	size = sizeof(t_philosopher) * conf->number_of_philosopher;
	if (!(*philosopher_array = (t_philosopher *)malloc(size)))
	{
		pthread_mutex_destroy(&conf->mutex);
		free(*fork_array);
		return (EXIT_FAILURE);
	}
	memset(*philosopher_array, 0, size);
	return (EXIT_SUCCESS);
}

int			main(int ac, char **av)
{
	t_config		conf;
	pthread_mutex_t	*fork_array;
	t_philosopher	*philosopher_array;
	int				ret;
	size_t			n;

	if (config(&conf, ac, av))
		return (EXIT_FAILURE);
	if (alloc(&fork_array, &philosopher_array, &conf))
		return (EXIT_FAILURE);
	if (init(philosopher_array, fork_array, &conf))
		return (EXIT_FAILURE);
	ret = run(philosopher_array, &conf);
	n = conf.number_of_philosopher;
	clean(philosopher_array, fork_array, &conf.mutex, n);
	return (ret);
}
