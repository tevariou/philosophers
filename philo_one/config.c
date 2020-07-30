#include "philo_one.h"
#include <unistd.h>

int  config(t_config *conf, int ac, char **av)
{
    if (ac < 5)
    {
        write(2, USAGE, ft_strlen(USAGE));
        return (EXIT_FAILURE);
    }
    if ((conf->number_of_philosopher = ft_atos(av[1])) < 0)
        return (error(PARAMS));
    if ((conf->time_to_die = ft_atos(av[2])) < 0)
        return (error(PARAMS));
    if ((conf->time_to_eat = ft_atos(av[3])) < 0)
        return (error(PARAMS));
    if ((conf->time_to_sleep = ft_atos(av[4])) < 0)
        return (error(PARAMS));
    if (pthread_mutex_init(&conf->mutex, NULL))
        return (EXIT_FAILURE);
    conf->number_of_time_each_philosophers_must_eat = (ac == 6)
                                                      ? ft_atos(av[5]) : -1;
    conf->is_finished = false;
    return (EXIT_SUCCESS);
}