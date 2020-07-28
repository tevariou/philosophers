#include "philo_three.h"
#include "unistd.h"

int print_status(const char *status, size_t number, t_config *conf) {
    struct timeval time;

    gettimeofday(&time, NULL);
    sem_wait(conf->print);
    if (conf->is_finished) {
        sem_post(conf->print);
        return (EXIT_FAILURE);
    }
    ft_putnbr(timeval_to_msec(time));
    ft_putchar(' ');
    ft_putnbr(number);
    ft_putchar(' ');
    write(1, status, ft_strlen(status));
    ft_putchar('\n');
    sem_post(conf->print);
    return (EXIT_SUCCESS);
}