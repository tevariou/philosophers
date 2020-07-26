#include "philo_two.h"
#include <unistd.h>

static void     eating(t_philosopher *philosopher, unsigned int time_to_eat) {
    struct timeval time;

    gettimeofday(&time, NULL);
    sem_wait(philosopher->conf->print);
    print_status("is eating", philosopher->number + 1);
    sem_post(philosopher->conf->print);
    philosopher->state.last_eating = time;
    usleep(time_to_eat * 1000);
    philosopher->state.counter += 1;
}

static void     thinking(t_philosopher *philosopher) {
    sem_wait(philosopher->conf->print);
    print_status("is thinking", philosopher->number + 1);
    sem_post(philosopher->conf->print);
}

static void     sleeping(t_philosopher *philosopher) {
    sem_wait(philosopher->conf->print);
    print_status("is sleeping", philosopher->number + 1);
    sem_post(philosopher->conf->print);
    usleep(philosopher->conf->time_to_sleep * 1000);
}

static void     take_fork(t_philosopher * philosopher) {
    sem_wait(philosopher->conf->print);
    print_status("has taken a fork", philosopher->number + 1);
    sem_post(philosopher->conf->print);
}

_Noreturn void  *philosopher_run(void *arg)
{
    t_philosopher   *philosopher;

    philosopher = (t_philosopher *)arg;
    while (1) {
        thinking(philosopher);
        sem_wait(philosopher->conf->forks);
        take_fork(philosopher);
        take_fork(philosopher);
        eating(philosopher, philosopher->conf->time_to_eat);
        sem_post(philosopher->conf->forks);
        sleeping(philosopher);
    }
}
