#include "philo_two.h"

 void clean(t_philosopher *philo_array, t_config *conf)
{
    sem_close(conf->print);
    sem_close(conf->forks);
    free(philo_array);
}
