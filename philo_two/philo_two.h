#ifndef             PHILOSOPHERS_PHILO_TWO_H
#define             PHILOSOPHERS_PHILO_TWO_H

#include            <pthread.h>
#include            <sys/time.h>
#include            <stdlib.h>
#include            <stdbool.h>
#include            <semaphore.h>

#define             USAGE        "Usage: ./philosopher number_of_philosopher " \
                                 "time_to_die time_to_eat time_to_sleep " \
                                 "[number_of_time_each_philosophers_must_eat]\n"

typedef struct      s_state {
    struct timeval  last_eating;
    int             counter;
}                   t_state;

typedef struct      s_config {
    size_t          number_of_philosopher;
    unsigned int    time_to_die;
    unsigned int    time_to_eat;
    unsigned int    time_to_sleep;
    int             number_of_time_each_philosophers_must_eat;
    bool            is_finished;
    sem_t           *forks;
    sem_t           *print;
}                   t_config;

typedef struct      s_philosopher {
    size_t          number;
    pthread_t       thread;
    t_state         state;
    t_config        *conf;
}                   t_philosopher;

size_t	            ft_strlen(const char *s);
int		            ft_atoi(const char *str);
void	            ft_putchar(char c);
void	            ft_putnbr(uint64_t n);
uint64_t            timeval_to_msec(struct timeval time);
bool                timeval_cmp(struct timeval a, struct timeval b);
struct timeval      timeval_add(struct timeval a, unsigned int b);
int                 print_status(const char *status, size_t number, t_config *conf);
void                *philosopher_run(void *arg);
void                *monitor_run(void *arg);
int                 config(t_config *conf, int ac, char **av);

#endif
