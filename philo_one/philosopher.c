#include "philo_one.h"
#include <unistd.h>

void eating(t_philosopher *philosopher, unsigned int time_to_eat) {
    struct timeval time;

    gettimeofday(&time, NULL);
    pthread_mutex_lock(&philosopher->conf->mutex);
    print_status("is eating", philosopher->number + 1);
    pthread_mutex_unlock(&philosopher->conf->mutex);
    philosopher->state.last_eating = time;
    usleep(time_to_eat * 1000);
    philosopher->state.counter += 1;
}

void thinking(t_philosopher *philosopher) {
    pthread_mutex_lock(&philosopher->conf->mutex);
    print_status("is thinking", philosopher->number + 1);
    pthread_mutex_unlock(&philosopher->conf->mutex);
}

void sleeping(t_philosopher *philosopher) {
    pthread_mutex_lock(&philosopher->conf->mutex);
    print_status("is sleeping", philosopher->number + 1);
    pthread_mutex_unlock(&philosopher->conf->mutex);
    usleep(philosopher->conf->time_to_sleep * 1000);
}

_Noreturn void *philosopher_run(void *arg)
{
    t_config        *conf;
    t_philosopher   *philosopher;
    pthread_mutex_t *first;
    pthread_mutex_t *second;

    philosopher = (t_philosopher *)arg;
    conf = philosopher->conf;
    first = (philosopher->left > philosopher->right) ? philosopher->right : philosopher->left;
    second = (philosopher->left > philosopher->right) ? philosopher->left : philosopher->right;
    while (1) {
        thinking(philosopher);
        pthread_mutex_lock(first);
        pthread_mutex_lock(&philosopher->conf->mutex);
        print_status("has taken a fork", philosopher->number + 1);
        pthread_mutex_unlock(&philosopher->conf->mutex);
        pthread_mutex_lock(second);
        pthread_mutex_lock(&philosopher->conf->mutex);
        print_status("has taken a fork", philosopher->number + 1);
        pthread_mutex_unlock(&philosopher->conf->mutex);
        eating(philosopher, conf->time_to_eat);
        pthread_mutex_unlock(second);
        pthread_mutex_unlock(first);
        sleeping(philosopher);
    }
}

