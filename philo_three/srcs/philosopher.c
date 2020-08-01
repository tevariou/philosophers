#include "philo_three.h"
#include <unistd.h>

static void		eating(t_philosopher *philosopher) {
	struct timeval	time;
	size_t			n;

	n = philosopher->number;
	gettimeofday(&time, NULL);
	print_status("is eating", n + 1, philosopher->conf);
	philosopher->state.last_eating = time;
	usleep(philosopher->conf->time_to_eat * 1000);
	sem_post(philosopher->conf->forks);
	sem_post(philosopher->conf->forks);
	n = philosopher->conf->number_of_time_each_philosophers_must_eat;
	if (++philosopher->state.counter == (int)n)
		exit(0);
}

static void		sleeping(t_philosopher *philosopher) {
	size_t	n;

	n = philosopher->number;
	print_status("is sleeping", n + 1, philosopher->conf);
	usleep(philosopher->conf->time_to_sleep * 1000);
}

static void		take_fork(t_philosopher *philosopher) {
	size_t	n;

	n = philosopher->number;
	sem_wait(philosopher->conf->forks);
	print_status("has taken a fork", n + 1, philosopher->conf);
	sem_wait(philosopher->conf->forks);
	print_status("has taken a fork", n + 1, philosopher->conf);
}

_Noreturn void	even_philosopher_run(t_philosopher *philosopher)
{
	size_t	n;

	gettimeofday(&philosopher->state.last_eating, NULL);
	n = philosopher->number;
	while (1) {
		print_status("is thinking", n + 1, philosopher->conf);
		take_fork(philosopher);
		eating(philosopher);
		sleeping(philosopher);
	}
}

_Noreturn void  odd_philosopher_run(t_philosopher *philosopher)
{
	size_t	n;

	gettimeofday(&philosopher->state.last_eating, NULL);
	n = philosopher->number;
	while (1) {
		sleeping(philosopher);
		print_status("is thinking", n + 1, philosopher->conf);
		take_fork(philosopher);
		eating(philosopher);
	}
}
