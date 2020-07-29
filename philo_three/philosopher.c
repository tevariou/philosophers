#include "philo_three.h"
#include <unistd.h>

static void     eating(t_philosopher *philosopher, unsigned int time_to_eat) {
    struct timeval time;
    size_t         n;

    n = philosopher->number;
    gettimeofday(&time, NULL);
    print_status("is eating", n + 1, philosopher->conf);
    philosopher->state.last_eating = time;
    usleep(time_to_eat * 1000);
    philosopher->state.counter += 1;
    n = philosopher->conf->number_of_time_each_philosophers_must_eat;
    if (philosopher->state.counter == n)
        exit(0);
}

static void     sleeping(t_philosopher *philosopher) {
    size_t n;

    n = philosopher->number;
    print_status("is sleeping", n + 1, philosopher->conf);
    usleep(philosopher->conf->time_to_sleep * 1000);
}

_Noreturn void  philosopher_run(t_philosopher *philosopher)
{
    size_t          n;

    n = philosopher->number;
    while (1) {
        print_status("is thinking", n + 1, philosopher->conf);
        sem_wait(philosopher->conf->forks);
        print_status("has taken a fork", n + 1, philosopher->conf);
        print_status("has taken a fork", n + 1, philosopher->conf);
        eating(philosopher, philosopher->conf->time_to_eat);
        sem_post(philosopher->conf->forks);
        sleeping(philosopher);
    }
}
