#ifndef             PHILOSOPHERS_PHILO_ONE_H
#define             PHILOSOPHERS_PHILO_ONE_H

#include            <pthread.h>
#include            <sys/time.h>
#include            <stdlib.h>
#include            <stdbool.h>

#define             USAGE        "Usage: ./philosopher number_of_philosopher " \
								 "time_to_die time_to_eat time_to_sleep " \
								 "[number_of_time_each_philosophers_must_eat]\n"
#define             PARAMS       "Params must be short numbers\n"

typedef struct      s_state {
	struct timeval  last_eating;
	int             counter;
}                   t_state;

typedef struct      s_config {
	size_t          number_of_philosopher;
	int             time_to_die;
	int             time_to_eat;
	int             time_to_sleep;
	int             number_of_time_each_philosophers_must_eat;
	pthread_mutex_t mutex;
	bool            is_finished;
}                   t_config;

typedef struct      s_philosopher {
	size_t          number;
	pthread_t       thread;
	t_state         state;
	pthread_mutex_t *left;
	pthread_mutex_t *right;
	t_config        *conf;
}                   t_philosopher;

size_t	            ft_strlen(const char *s);
short	            ft_atos(const char *str);
void	            ft_putnbr(char *s, uint64_t n);
void                ft_append(char *dest, const char *str);
void	            ft_putstr_fd(char const *s, int fd);
int	                ft_strcmp(const char *s1, const char *s2);
uint64_t            timeval_to_msec(struct timeval time);
int                 timeval_cmp(struct timeval a, struct timeval b);
struct timeval      timeval_add(struct timeval a, unsigned int b);
int                 print_status(const char *status, size_t number,
						t_config *conf);
void                *even_philosopher_run(void *arg);
void                *odd_philosopher_run(void *arg);
void                *monitor_run(void *arg);
int                 config(t_config *conf, int ac, char **av);
void                clean(t_philosopher *philosopher_array,
						pthread_mutex_t *fork_array,pthread_mutex_t
						*mutex,size_t n);

#endif