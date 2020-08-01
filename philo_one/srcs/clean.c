#include "philo_one.h"

void clean(
        t_philosopher   *philosopher_array,
        pthread_mutex_t *fork_array,
        pthread_mutex_t *mutex,
        size_t          n
)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        pthread_mutex_destroy(&fork_array[i]);
        i++;
    }
    pthread_mutex_destroy(mutex);
    free(philosopher_array);
    free(fork_array);
}
