#include "philo_two.h"
#include <unistd.h>
#include <string.h>

static void  init(
            t_philosopher   *philosopher_array,
            t_config        *main_conf
        )
{
    size_t          i;
    size_t          n;
    struct timeval  last_eating;

    n = main_conf->number_of_philosopher;
    i = 0;
    while (i < n)
    {
        philosopher_array[i].conf = main_conf;
        philosopher_array[i].number = i;
        philosopher_array[i].state.counter = 0;
        gettimeofday(&last_eating, NULL);
        philosopher_array[i].state.last_eating = last_eating;
        i++;
    }
}

static void clean(t_philosopher *philo_array, size_t n) {
    memset(philo_array, 0, n);
    free(philo_array);
}

static int  run(
            t_philosopher   *philo_array,
            t_config        *conf
        )
{
    size_t      i;
    size_t      n;
    pthread_t   monitor;

    n = conf->number_of_philosopher;
    i = 0;
    while (i < n)
    {
        if (pthread_create(&philo_array[i].thread, NULL, &philosopher_run, &philo_array[i]))
        {
            clean(philo_array, n);
            return (EXIT_FAILURE);
        }
        i++;
    }
    if (pthread_create(&monitor, NULL, &monitor_run, philo_array))
    {
        clean(philo_array, n);
        return (EXIT_FAILURE);
    }
    pthread_detach(monitor);
    i = 0;
    while (i < n)
    {
        pthread_join(philo_array[i].thread, NULL);
        i++;
    }
    clean(philo_array, n);
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
    size_t          size;
    t_philosopher   *philosopher_array;

    if (config(&conf, ac, av))
        return (EXIT_FAILURE);
    if (sem_create(&conf))
        return (EXIT_FAILURE);
    size = sizeof(t_philosopher) * conf.number_of_philosopher;
    if (!(philosopher_array = (t_philosopher *)malloc(size)))
        return (EXIT_FAILURE);
	init(philosopher_array, &conf);
	run(philosopher_array, &conf);
	return (EXIT_SUCCESS);
}
