#include "philo_one.h"
#include <unistd.h>

int     config(t_config *conf, int ac, char **av)
{
	if (ac < 5) {
	    write(2, USAGE, ft_strlen(USAGE));
		return (EXIT_FAILURE);
	}
	conf->number_of_philosopher = ft_atoi(av[1]);
	conf->time_to_die = ft_atoi(av[2]);
	conf->time_to_eat = ft_atoi(av[3]);
	conf->time_to_sleep = ft_atoi(av[4]);
	pthread_mutex_init(&conf->mutex, NULL);
	if (ac == 6) {
		conf->number_of_time_each_philosophers_must_eat = ft_atoi(av[5]);
	} else {
	    conf->number_of_time_each_philosophers_must_eat = -1;
	}
	return (EXIT_SUCCESS);
}

void    init(
            t_philosopher *philosopher_array,
            pthread_mutex_t *fork_array,
            t_config *main_conf
        )
{
    size_t          i;
    size_t          number_of_philosopher;
    struct timeval  last_eating;

    number_of_philosopher = main_conf->number_of_philosopher;
    i = 0;
    while (i < number_of_philosopher) {
        pthread_mutex_init(&fork_array[i], NULL);
        philosopher_array[i].conf = main_conf;
        philosopher_array[i].left = fork_array + i;
        philosopher_array[i].right = i ? fork_array + i - 1 : fork_array + number_of_philosopher - 1;
        philosopher_array[i].number = i;
        philosopher_array[i].state.counter = 0;
        gettimeofday(&last_eating, NULL);
        philosopher_array[i].state.last_eating = last_eating;
        i++;
    }
}

void    clean(
        t_philosopher *philosopher_array,
        pthread_mutex_t *fork_array,
        t_config *conf
) {
    size_t i;

    i = 0;
    while (i < conf->number_of_philosopher) {
        pthread_mutex_destroy(&fork_array[i]);
        i++;
    }
    pthread_mutex_destroy(&conf->mutex);
    free(philosopher_array);
    free(fork_array);
}

int     run(
            t_philosopher *philosopher_array,
            pthread_mutex_t *fork_array,
            t_config *conf
        ) {
    size_t i;
    pthread_t monitor;

    i = 0;
    while (i < conf->number_of_philosopher) {
        if (pthread_create(&philosopher_array[i].thread, NULL, &philosopher_run, &philosopher_array[i])) {
            clean(philosopher_array, fork_array, conf);
            return (EXIT_FAILURE);
        }
        i++;
    }
    i = 0;
    while (i < conf->number_of_philosopher) {
        pthread_detach(philosopher_array[i].thread);
        i++;
    }
    if (pthread_create(&monitor, NULL, &monitor_run, philosopher_array)) {
        clean(philosopher_array, fork_array, conf);
        return (EXIT_FAILURE);
    }
    pthread_join(monitor, NULL);
    return (EXIT_SUCCESS);
}

int     main(int ac, char** av) {
	t_config        conf;
	pthread_mutex_t *fork_array;
	t_philosopher   *philosopher_array;
    size_t          size;

	if (config(&conf, ac, av)) {
		return (EXIT_FAILURE);
	}
	size = sizeof(pthread_mutex_t) * conf.number_of_philosopher;
	if (!(fork_array = (pthread_mutex_t *)malloc(size))) {
        return (EXIT_FAILURE);
    }
	size = sizeof(*philosopher_array) * conf.number_of_philosopher;
    if (!(philosopher_array = (t_philosopher *)malloc(size))) {
        free(fork_array);
        return (EXIT_FAILURE);
    }
	init(philosopher_array, fork_array, &conf);
	return (run(philosopher_array, fork_array, &conf));
}
