#include "philo_three.h"
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

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

static int	run(
	t_philosopher *philo_array,
	pid_t *pid_array,
	t_config *conf
)
{
	size_t		i;
	pthread_t	monitor;
	int			status;

	i = 0;
	while (i < conf->number_of_philosopher)
	{
		pid_array[i] = fork();
		if (pid_array[i] == 0)
		{
			if (pthread_create(&monitor, NULL, &monitor_run, philo_array + i))
				break ;
			pthread_detach(monitor);
			if (!(i % 2))
				even_philosopher_run(philo_array + i);
			else
				odd_philosopher_run(philo_array + i);
		}
		i++;
	}
	waitpid(-1, &status, 0);
	clean(philo_array, pid_array, conf);
	return (EXIT_SUCCESS);
}

static int	sem_create(t_config *conf)
{
	size_t	n;

	n = conf->number_of_philosopher;
	conf->forks = sem_open("forks", O_CREAT | O_EXCL, 0600, n);
	sem_unlink("forks");
	if (conf->forks == SEM_FAILED)
		return (EXIT_FAILURE);
	conf->print = sem_open("print", O_CREAT | O_EXCL, 0600, 1);
	sem_unlink("print");
	if (conf->print == SEM_FAILED)
	{
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
	pid_t			*pid_array;

	if (config(&conf, ac, av))
		return (EXIT_FAILURE);
	size = sizeof(t_philosopher) * conf.number_of_philosopher;
	if (!(philosopher_array = (t_philosopher *)malloc(size)))
		return (EXIT_FAILURE);
	size = sizeof(pid_t) * conf.number_of_philosopher;
	if (!(pid_array = (pid_t *)malloc(sizeof(pid_t) * size)))
	{
		free(philosopher_array);
		return (EXIT_FAILURE);
	}
	if (sem_create(&conf))
		return (EXIT_FAILURE);
	init(philosopher_array, &conf);
	return (run(philosopher_array, pid_array, &conf));
}
