#include "philo_two.h"

static void	init(t_philosopher *philosopher_array, t_config *main_conf)
{
	size_t	i;
	size_t	n;

	n = main_conf->number_of_philosopher;
	i = 0;
	while (i < n)
	{
		philosopher_array[i].conf = main_conf;
		philosopher_array[i].number = i;
		philosopher_array[i].state.counter = 0;
		philosopher_array[i].state.last_eating.tv_sec = 0;
		philosopher_array[i].state.last_eating.tv_usec = 0;
		i++;
	}
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
		f = (i % 2 == 0) ? &even_philosopher_run : &odd_philosopher_run;
		if (pthread_create(&philo_array[i].thread, NULL, f, philo_array + i))
		{
			clean(philo_array, conf);
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (pthread_create(&monitor, NULL, &monitor_run, philo_array))
	{
		clean(philo_array, conf);
		return (EXIT_FAILURE);
	}
	pwait(philo_array, conf, &monitor);
	clean(philo_array, conf);
	return (EXIT_SUCCESS);
}

static int	sem_create(t_config *conf) {
	size_t	n;

	n = conf->number_of_philosopher;
	conf->forks = sem_open("forks", O_CREAT | O_EXCL, 0600, n);
	sem_unlink("forks");
	if (conf->forks == SEM_FAILED)
		return (EXIT_FAILURE);
	conf->print = sem_open("print", O_CREAT | O_EXCL, 0600, 1);
	sem_unlink("print");
	if (conf->print == SEM_FAILED) {
		sem_close(conf->forks);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int			main(int ac, char **av)
{
	t_config		conf;
	size_t			size;
	t_philosopher	*philosopher_array;

	if (config(&conf, ac, av))
		return (EXIT_FAILURE);
	if (sem_create(&conf))
		return (EXIT_FAILURE);
	size = sizeof(t_philosopher) * conf.number_of_philosopher;
	if (!(philosopher_array = (t_philosopher *)malloc(size)))
		return (EXIT_FAILURE);
	init(philosopher_array, &conf);
	return (run(philosopher_array, &conf));
}
