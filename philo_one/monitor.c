#include "philo_one.h"

void *monitor_run(void *arg) {
    t_philosopher   *philosopher_array;
    struct timeval  time;
    size_t          i;
    size_t          number_of_philosopher;
    size_t          counter;

    philosopher_array = (t_philosopher *)arg;
    i = 0;
    while (1) {
        counter = 0;
        number_of_philosopher = philosopher_array[i].conf->number_of_philosopher;
        while (i < number_of_philosopher) {
            gettimeofday(&time, NULL);
            if (timeval_cmp(time, timeval_add(philosopher_array[i].state.last_eating, philosopher_array[i].conf->time_to_die))) {
                pthread_mutex_lock(&philosopher_array[i].conf->mutex);
                print_status("died", i + 1);
                return (NULL);
            }
            if (philosopher_array[i].conf->number_of_time_each_philosophers_must_eat >= 0
                && philosopher_array[i].state.counter >= philosopher_array[i].conf->number_of_time_each_philosophers_must_eat) {
                counter += 1;
            }
            i++;
        }
        i = 0;
        pthread_mutex_lock(&philosopher_array[i].conf->mutex);
        if (counter == number_of_philosopher) {
            return (NULL);
        }
        pthread_mutex_unlock(&philosopher_array[i].conf->mutex);
    }
}