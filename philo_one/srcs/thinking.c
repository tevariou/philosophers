#include "philo_one.h"

static bool	is_turn(t_philosopher *philosopher, size_t n, size_t total)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(&philosopher->conf->mutex);
	if (philosopher->conf->wait == n)
	{
		philosopher->conf->wait += 1;
		if (philosopher->conf->wait == total)
			philosopher->conf->wait = 0;
		ret = true;
	}
	pthread_mutex_unlock(&philosopher->conf->mutex);
	return (ret);
}

int			thinking(t_philosopher *philosopher)
{
	size_t	n;
	size_t	total;
	int 	time_to_wait;

	n = philosopher->number;
	total = philosopher->conf->number_of_philosopher;
	if (print_status("is thinking", n + 1, philosopher->conf))
		return (EXIT_FAILURE);
	time_to_wait = philosopher->conf->time_to_sleep - 10;
	if (total % 2 == 0 || time_to_wait <= 0)
		return (EXIT_SUCCESS);
	if (is_turn(philosopher, n, total))
		ft_sleep(time_to_wait);
	return (EXIT_SUCCESS);
}
