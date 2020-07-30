#include "philo_three.h"
#include <unistd.h>

void print_(const char *status, size_t number, t_config *conf) {
    struct timeval time;

    gettimeofday(&time, NULL);
    ft_putnbr(timeval_to_msec(time));
    ft_putchar(' ');
    ft_putnbr(number);
    ft_putchar(' ');
    write(1, status, ft_strlen(status));
    ft_putchar('\n');
}

static void is_alive(t_philosopher *philosopher) {
    struct timeval  time;
    struct timeval  last_eating;
    unsigned int    time_to_die;

    gettimeofday(&time, NULL);
    last_eating = philosopher->state.last_eating;
    if (!last_eating.tv_sec)
        return;
    time_to_die = philosopher->conf->time_to_die;
    if (timeval_cmp(time, timeval_add(last_eating, time_to_die)))
    {
        sem_wait(philosopher->conf->print);
        print_("died", philosopher->number + 1, philosopher->conf);
        exit(0);
    }
}

_Noreturn void        *monitor_run(void *arg) {
    t_philosopher   *philosopher;

    philosopher = (t_philosopher *)arg;
    while (1)
        is_alive(philosopher);
}