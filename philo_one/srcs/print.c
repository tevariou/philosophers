#include "philo_one.h"
#include "unistd.h"
#include <string.h>

int print_status(const char *status, size_t number, t_config *conf) {
    struct timeval time;
    char           str[34];

    gettimeofday(&time, NULL);
    pthread_mutex_lock(&conf->mutex);
    if (conf->is_finished) {
        pthread_mutex_unlock(&conf->mutex);
        return (EXIT_FAILURE);
    }
    if (!ft_strcmp("died", status))
        conf->is_finished = true;
    memset(str, 0, 34);
    ft_putnbr(str, timeval_to_msec(time));
    ft_append(str, " ");
    ft_putnbr(str, number);
    ft_append(str, " ");
    ft_append(str, status);
    ft_append(str, "\n");
    ft_putstr_fd(str, 1);
    pthread_mutex_unlock(&conf->mutex);
    return (EXIT_SUCCESS);
}