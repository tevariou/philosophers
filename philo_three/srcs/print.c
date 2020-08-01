#include "philo_three.h"
#include <string.h>

void print_status(const char *status, size_t number, t_config *conf) {
    char            str[34];
    struct timeval time;

    gettimeofday(&time, NULL);
    sem_wait(conf->print);
    memset(str, 0, 34);
    ft_putnbr(str, timeval_to_msec(time));
    ft_append(str, " ");
    ft_putnbr(str, number);
    ft_append(str, " ");
    ft_append(str, status);
    ft_append(str, "\n");
    ft_putstr_fd(str, 1);
    if (ft_strcmp(status, "died"))
        sem_post(conf->print);
}