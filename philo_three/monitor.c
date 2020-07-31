#include "philo_three.h"
#include <unistd.h>
#include <string.h>

void print_(const char *status, size_t number) {
    char            str[34];
    struct timeval  time;

    gettimeofday(&time, NULL);
    memset(str, 0, 34);
    ft_putnbr(str, timeval_to_msec(time));
    ft_append(str, " ");
    ft_putnbr(str, number);
    ft_append(str, " ");
    ft_append(str, status);
    ft_append(str, "\n");
    ft_putstr_fd(str, 1);
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
        print_("died", philosopher->number + 1);
        exit(0);
    }
}

_Noreturn void        *monitor_run(void *arg) {
    t_philosopher   *philosopher;

    philosopher = (t_philosopher *)arg;
    while (1)
        is_alive(philosopher);
}