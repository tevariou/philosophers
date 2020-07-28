#include "philo_three.h"
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

static void  init(t_philosopher *philosopher_array, t_config *main_conf)
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

static void clean(t_philosopher *philo_array, t_config *conf, size_t n) {
    sem_close(conf->print);
    sem_close(conf->forks);
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
    pid_t       *pid_array;
    int         status;

    n = conf->number_of_philosopher;
    if (!(pid_array = (pid_t *)malloc(sizeof(pid_t) * n))) {
        return (EXIT_FAILURE);
    }
    i = 0;
    while (i < n)
    {
        pid_array[i] = fork();
        if (pid_array[i] == 0) {
            if (pthread_create(&monitor, NULL, &monitor_run, philo_array))
            {
                clean(philo_array, conf, n);
                return (EXIT_FAILURE);
            }
            pthread_detach(monitor);
            philosopher_run(philo_array + i);
        }
        i++;
    }
    i = 0;
    while (i < conf->number_of_philosopher) {
        waitpid(pid_array[i], &status, 0);
        if (WIFEXITED(status))
            free(pid_array);
            return (EXIT_SUCCESS);
        i++;
    }
    free(pid_array);
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
	clean(philosopher_array, &conf, conf.number_of_philosopher);
	return (EXIT_SUCCESS);
}
