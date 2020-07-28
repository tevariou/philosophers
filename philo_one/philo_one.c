#include "philo_one.h"
#include <unistd.h>
#include <string.h>

static void clean(
        t_philosopher   *philosopher_array,
        pthread_mutex_t *fork_array,
        pthread_mutex_t *mutex,
        size_t          n
)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        pthread_mutex_destroy(&fork_array[i]);
        i++;
    }
    pthread_mutex_destroy(mutex);
    memset(fork_array, 0, n);
    memset(philosopher_array, 0, n);
    free(philosopher_array);
    free(fork_array);
}

static int  init(
            t_philosopher   *philosopher_array,
            pthread_mutex_t *fork_array,
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
        if (pthread_mutex_init(&fork_array[i], NULL))
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
        gettimeofday(&last_eating, NULL);
        philosopher_array[i].state.last_eating = last_eating;
        i++;
    }
    return (EXIT_SUCCESS);
}

static int  run(
            t_philosopher   *philo_array,
            pthread_mutex_t *fork_array,
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
        if (pthread_create(&philo_array[i].thread, NULL, &philosopher_run, philo_array + i))
        {
            clean(philo_array, fork_array, &conf->mutex, n);
            return (EXIT_FAILURE);
        }
        i++;
    }
    if (pthread_create(&monitor, NULL, &monitor_run, philo_array))
    {
        clean(philo_array, fork_array, &conf->mutex, n);
        return (EXIT_FAILURE);
    }
    pthread_detach(monitor);
    i = 0;
    while (i < n)
    {
        pthread_join(philo_array[i].thread, NULL);
        i++;
    }
    clean(philo_array, fork_array, &conf->mutex, n);
    return (EXIT_SUCCESS);
}

static int  alloc(
            pthread_mutex_t **fork_array,
            t_philosopher   **philosopher_array,
            t_config        *conf
        )
{
    size_t size;

    size = sizeof(pthread_mutex_t) * conf->number_of_philosopher;
    if (!(*fork_array = (pthread_mutex_t *)malloc(size)))
    {
        pthread_mutex_destroy(&conf->mutex);
        return (EXIT_FAILURE);
    }
    size = sizeof(t_philosopher) * conf->number_of_philosopher;
    if (!(*philosopher_array = (t_philosopher *)malloc(size)))
    {
        pthread_mutex_destroy(&conf->mutex);
        free(*fork_array);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int         main(int ac, char** av)
{
	t_config        conf;
	pthread_mutex_t *fork_array;
	t_philosopher   *philosopher_array;

    if (config(&conf, ac, av))
        return (EXIT_FAILURE);
    if (alloc(&fork_array, &philosopher_array, &conf))
        return (EXIT_FAILURE);
	if (init(philosopher_array, fork_array, &conf))
	    return (EXIT_FAILURE);
	return (run(philosopher_array, fork_array, &conf));
}
