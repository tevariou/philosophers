#include "philo_three.h"

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
        philosopher->conf->is_finished = true;
        return (false);
    }
    return (true);
}

static bool is_finished(t_philosopher *philosopher) {
    int number;

    number = philosopher->conf->number_of_time_each_philosophers_must_eat;
    return ((number >= 0 && philosopher->state.counter >= number));
}

static bool is_all_done(t_philosopher * philosopher, size_t counter)
{
    if (counter == philosopher->conf->number_of_philosopher)
    {
        philosopher->conf->is_finished = true;
        return (true);
    }
    return (false);
}

void        *monitor_run(void *arg) {
    t_philosopher   *philosopher_array;
    size_t          i;
    size_t          number_of_philosopher;
    size_t          counter;

    philosopher_array = (t_philosopher *)arg;
    i = 0;
    while (1)
    {
        counter = 0;
        number_of_philosopher = philosopher_array[i].conf->number_of_philosopher;
        while (i < number_of_philosopher)
        {
            if (!is_alive(philosopher_array + i, i))
                return (NULL);
            if (is_finished(philosopher_array + i))
                counter += 1;
            i++;
        }
        i = 0;
        if (is_all_done(philosopher_array + i, counter))
            return (NULL);
    }
}