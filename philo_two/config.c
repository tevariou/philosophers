#include "philo_two.h"
#include <unistd.h>

int  config(t_config *conf, int ac, char **av)
{
    if (ac < 5)
    {
        write(2, USAGE, ft_strlen(USAGE));
        return (EXIT_FAILURE);
    }
    conf->number_of_philosopher = ft_atoi(av[1]);
    conf->time_to_die = ft_atoi(av[2]);
    conf->time_to_eat = ft_atoi(av[3]);
    conf->time_to_sleep = ft_atoi(av[4]);
    conf->number_of_time_each_philosophers_must_eat = (ac == 6)
                                                      ? ft_atoi(av[5]) : -1;
    return (EXIT_SUCCESS);
}