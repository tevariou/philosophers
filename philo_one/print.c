#include "philo_one.h"
#include "unistd.h"

int print_status(const char *status, size_t number, t_config *conf) {
    struct timeval time;

    gettimeofday(&time, NULL);
    pthread_mutex_lock(&conf->mutex);
    if (conf->is_finished) {
        pthread_mutex_unlock(&conf->mutex);
        return (EXIT_FAILURE);
    }
    if (!ft_strcmp("died", status))
        conf->is_finished = true;
    ft_putnbr(timeval_to_msec(time));
    ft_putchar(' ');
    ft_putnbr(number);
    ft_putchar(' ');
    write(1, status, ft_strlen(status));
    ft_putchar('\n');
    pthread_mutex_unlock(&conf->mutex);
    return (EXIT_SUCCESS);
}