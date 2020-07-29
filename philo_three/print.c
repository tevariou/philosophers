#include "philo_three.h"
#include "unistd.h"

void print_status(const char *status, size_t number, t_config *conf) {
    struct timeval time;

    gettimeofday(&time, NULL);
    sem_wait(conf->print);
    ft_putnbr(timeval_to_msec(time));
    ft_putchar(' ');
    ft_putnbr(number);
    ft_putchar(' ');
    write(1, status, ft_strlen(status));
    ft_putchar('\n');
    sem_post(conf->print);
}