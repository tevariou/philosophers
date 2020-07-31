#include "philo_three.h"
#include <string.h>

static void     is_alive(t_philosopher *philosopher) {
    struct timeval  time;
    struct timeval  last_eating;
    unsigned int    time_to_die;

    gettimeofday(&time, NULL);
    last_eating = philosopher->state.last_eating;
    time_to_die = philosopher->conf->time_to_die;
    if (last_eating.tv_sec
        && timeval_cmp(time, timeval_add(last_eating, time_to_die)) >= 0)
    {
        print_status("died", philosopher->number + 1, philosopher->conf);
        exit(0);
    }
}

_Noreturn void  *monitor_run(void *arg) {
    t_philosopher   *philosopher;

    philosopher = (t_philosopher *)arg;
    while (1)
        is_alive(philosopher);
}