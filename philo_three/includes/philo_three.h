#ifndef PHILOSOPHERS_PHILO_THREE_H
#define PHILOSOPHERS_PHILO_THREE_H

#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <semaphore.h>
#include <stdint.h>

#define USAGE	"Usage: ./philosopher number_of_philosopher " \
				"time_to_die time_to_eat time_to_sleep " \
				"[number_of_time_each_philosophers_must_eat]\n"
#define PARAMS	"Params must be short numbers\n"

typedef struct		s_state {
	struct timeval	last_eating;
	int				counter;
}					t_state;

typedef struct		s_config {
	size_t			number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_time_each_philosophers_must_eat;
	sem_t			*forks;
	sem_t			*print;
}					t_config;

typedef struct		s_philosopher {
	size_t			number;
	pthread_t		thread;
	t_state			state;
	t_config		*conf;
}					t_philosopher;

size_t				ft_strlen(const char *s);
short				ft_atos(const char *str);
void				ft_putnbr(char *s, uint64_t n);
void				ft_append(char *dest, const char *str);
void				ft_putstr_fd(char const *s, int fd);
int					ft_strcmp(const char *s1, const char *s2);
uint64_t			timeval_to_msec(struct timeval time);
int					timeval_cmp(struct timeval a, struct timeval b);
struct timeval		timeval_add(struct timeval a, unsigned int b);
void				print_status(const char *status, size_t number,
						t_config *conf);
_Noreturn void		even_philosopher_run(t_philosopher *philosopher);
_Noreturn void		odd_philosopher_run(t_philosopher *philosopher);
_Noreturn void		*monitor_run(void *arg);
int					config(t_config *conf, int ac, char **av);

#endif
