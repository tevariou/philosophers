#include "philo_two.h"
#include <unistd.h>

static int     eating(t_philosopher *philosopher, unsigned int time_to_eat) {
    struct timeval time;
    size_t         n;

    n = philosopher->number;
    gettimeofday(&time, NULL);
    if (print_status("is eating", n + 1, philosopher->conf))
        return (EXIT_FAILURE);
    philosopher->state.last_eating = time;
    usleep(time_to_eat * 1000);
    philosopher->state.counter += 1;
    return (EXIT_SUCCESS);
}

static int     sleeping(t_philosopher *philosopher) {
    size_t n;

    n = philosopher->number;
    if (print_status("is sleeping", n + 1, philosopher->conf))
        return (EXIT_FAILURE);
    usleep(philosopher->conf->time_to_sleep * 1000);
    return (EXIT_SUCCESS);
}

void  *philosopher_run(void *arg)
{
    t_philosopher   *philosopher;
    size_t          n;

    philosopher = (t_philosopher *)arg;
    n = philosopher->number;
    while (1) {
        if (print_status("is thinking", n + 1, philosopher->conf))
            return (NULL);
        sem_wait(philosopher->conf->forks);
        if (print_status("has taken a fork", n + 1, philosopher->conf))
            return (NULL);
        if (print_status("has taken a fork", n + 1, philosopher->conf))
            return (NULL);
        if (eating(philosopher, philosopher->conf->time_to_eat))
            return (NULL);
        sem_post(philosopher->conf->forks);
        if (sleeping(philosopher))
            return (NULL);
    }
}
