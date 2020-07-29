#include "philo_two.h"

static bool is_alive(t_philosopher *philosopher, size_t number) {
    struct timeval  time;
    struct timeval  last_eating;
    unsigned int    time_to_die;

    gettimeofday(&time, NULL);
    last_eating = philosopher->state.last_eating;
    time_to_die = philosopher->conf->time_to_die;
    if (timeval_cmp(time, timeval_add(last_eating, time_to_die)))
    {
        print_status("died", number + 1, philosopher->conf);
        return (false);
    }
    return (true);
}

_Noreturn void        *monitor_run(void *arg) {
    t_philosopher   *philosopher_array;
    size_t          i;
    size_t          n;

    philosopher_array = (t_philosopher *)arg;
    i = 0;
    while (1)
    {
        n = philosopher_array[i].conf->number_of_philosopher;
        while (i < n)
        {
            if (!is_alive(philosopher_array + i, i))
                return (NULL);
            i++;
        }
        i = 0;
    }
}