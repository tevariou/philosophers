#include "philo_three.h"
#include <unistd.h>

static int  config(t_config *conf, int ac, char **av)
{
	if (ac < 5)
	{
	    write(2, USAGE, ft_strlen(USAGE));
		return (EXIT_FAILURE);
	}
	conf->number_of_philosopher = ft_atoi(av[1]);
	conf->time_to_die = ft_atoi(av[2]);
	conf->time_to_eat = ft_atoi(av[3]);
	conf->time_to_sleep = ft_atoi(av[4]);
	conf->number_of_time_each_philosophers_must_eat = (ac == 6)
	        ? ft_atoi(av[5]) : -1;
	return (EXIT_SUCCESS);
}

static int  init(t_philosopher *philosopher_array, t_config *main_conf)
{
    size_t          i;
    size_t          number_of_philosopher;
    struct timeval  last_eating;

    number_of_philosopher = main_conf->number_of_philosopher;
    i = 0;
    while (i < number_of_philosopher)
    {
        philosopher_array[i].conf = main_conf;
        philosopher_array[i].number = i;
        philosopher_array[i].state.counter = 0;
        gettimeofday(&last_eating, NULL);
        philosopher_array[i].state.last_eating = last_eating;
        i++;
    }
    return (EXIT_SUCCESS);
}

static int  run(t_philosopher *philosopher_array, t_config *conf)
{
    size_t i;
    pthread_t monitor;

    i = 0;
    while (i < conf->number_of_philosopher)
    {
        if (pthread_create(&philosopher_array[i].thread, NULL, &philosopher_run, &philosopher_array[i]))
            return (EXIT_FAILURE);
        i++;
    }
    i = 0;
    while (i < conf->number_of_philosopher)
    {
        pthread_detach(philosopher_array[i].thread);
        i++;
    }
    if (pthread_create(&monitor, NULL, &monitor_run, philosopher_array))
        return (EXIT_FAILURE);
    pthread_join(monitor, NULL);
    return (EXIT_SUCCESS);
}

static int  alloc(t_philosopher **philosopher_array, t_config *conf)
{
    size_t size;

    size = sizeof(t_philosopher) * conf->number_of_philosopher;
    if (!(*philosopher_array = (t_philosopher *)malloc(size)))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static int sem_create(t_config *conf) {
    conf->forks = sem_open("forks", O_CREAT | O_EXCL, 0600, conf->number_of_philosopher / 2);
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

int         main(int ac, char** av)
{
	t_config        conf;
	t_philosopher   *philosopher_array;

    if (config(&conf, ac, av))
        return (EXIT_FAILURE);
    if (sem_create(&conf))
        return (EXIT_FAILURE);
    if (alloc(&philosopher_array, &conf))
        return (EXIT_FAILURE);
	if (init(philosopher_array, &conf))
	    return (EXIT_FAILURE);
	return (run(philosopher_array, &conf));
}
