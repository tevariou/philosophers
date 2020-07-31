#include "philo_one.h"

static bool is_alive(t_philosopher *philosopher, size_t number) {
    struct timeval  time;
    struct timeval  last_eating;
    unsigned int    time_to_die;

    gettimeofday(&time, NULL);
    last_eating = philosopher->state.last_eating;
    time_to_die = philosopher->conf->time_to_die;
    if (last_eating.tv_sec
        && timeval_cmp(time, timeval_add(last_eating, time_to_die)) >= 0)
    {
        print_status("died", number + 1, philosopher->conf);
        return (false);
    }
    return (true);
}

void        *monitor_run(void *arg) {
    t_philosopher   *philosopher_array;
    t_config        *conf;
    size_t          i;
    size_t          counter;
    size_t          n;

    philosopher_array = (t_philosopher *)arg;
    conf = philosopher_array[0].conf;
    n = conf->number_of_time_each_philosophers_must_eat;
    while (1)
    {
        i = 0;
        counter = 0;
        while (i < conf->number_of_philosopher)
        {
            if (!is_alive(philosopher_array + i, i))
                return (NULL);
            if (philosopher_array[i].state.counter == n)
                counter++;
            i++;
        }
        if (counter == conf->number_of_philosopher)
            break;
    }
    return (NULL);
}