#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define USAGE   "Usage: ./philosopher number_of_philosopher " \
                "time_to_die time_to_eat time_to_sleep " \
                "[number_of_time_each_philosophers_must_eat]\n"
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

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
    pthread_mutex_t mutex;
}                   t_config;

typedef struct      s_philosopher {
    size_t          number;
    pthread_t       thread;
    t_state         state;
    pthread_mutex_t *left;
    pthread_mutex_t *right;
    t_config        *conf;
}                   t_philosopher;

size_t	ft_strlen(const char *s)
{
    size_t	len;

    len = 0;
    if (s)
    {
        while (s[len])
            len++;
    }
    return (len);
}

int		ft_atoi(const char *str)
{
    int		i;
    int		number;

    i = 0;
    number = 0;
    while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
           || (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
        i++;
    while ((str[i] >= '0') && (str[i] <= '9'))
    {
        number *= 10;
        number += ((int)str[i] - 48);
        i++;
    }
    return (number);
}

uint64_t timeval_to_msec(struct timeval time) {
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int config(t_config *conf, int ac, char **av)
{
	if (ac < 5) {
	    write(2, USAGE, ft_strlen(USAGE));
		return (EXIT_FAILURE);
	}
	conf->number_of_philosopher = ft_atoi(av[1]);
	conf->time_to_die = ft_atoi(av[2]);
	conf->time_to_eat = ft_atoi(av[3]);
	conf->time_to_sleep = ft_atoi(av[4]);
	pthread_mutex_init(&conf->mutex, NULL);
	if (ac == 6) {
		conf->number_of_time_each_philosophers_must_eat = ft_atoi(av[5]);
	} else {
	    conf->number_of_time_each_philosophers_must_eat = -1;
	}
	return (EXIT_SUCCESS);
}

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putnbr(uint64_t n)
{
    if (n >= 10)
        ft_putnbr(n / 10);
    ft_putchar((char)((int)'0' + n % 10));
}

void print_status(const char *status, size_t number) {
    struct timeval time;

    gettimeofday(&time, NULL);
    ft_putnbr(timeval_to_msec(time));
    ft_putchar(' ');
    ft_putnbr(number);
    ft_putchar(' ');
    write(1, status, ft_strlen(status));
    ft_putchar('\n');
}

void eating(t_philosopher *philosopher, unsigned int time_to_eat) {
    struct timeval time;

    gettimeofday(&time, NULL);
    pthread_mutex_lock(&philosopher->conf->mutex);
    print_status("is eating", philosopher->number + 1);
    pthread_mutex_unlock(&philosopher->conf->mutex);
    philosopher->state.last_eating = time;
    usleep(time_to_eat * 1000);
    philosopher->state.counter += 1;
}

void thinking(t_philosopher *philosopher) {
    pthread_mutex_lock(&philosopher->conf->mutex);
    print_status("is thinking", philosopher->number + 1);
    pthread_mutex_unlock(&philosopher->conf->mutex);
}

void sleeping(t_philosopher *philosopher) {
    pthread_mutex_lock(&philosopher->conf->mutex);
    print_status("is sleeping", philosopher->number + 1);
    pthread_mutex_unlock(&philosopher->conf->mutex);
    usleep(philosopher->conf->time_to_sleep * 1000);
}

_Noreturn void *philosopher_run(void *arg)
{
    t_config *conf;
    t_philosopher *philosopher;
    pthread_mutex_t *first;
    pthread_mutex_t *second;

    philosopher = (t_philosopher *)arg;
    conf = philosopher->conf;
    first = (philosopher->left > philosopher->right) ? philosopher->right : philosopher->left;
    second = (philosopher->left > philosopher->right) ? philosopher->left : philosopher->right;
    while (1) {
        thinking(philosopher);
        pthread_mutex_lock(first);
        pthread_mutex_lock(&philosopher->conf->mutex);
        print_status("has taken a fork", philosopher->number + 1);
        pthread_mutex_unlock(&philosopher->conf->mutex);
        pthread_mutex_lock(second);
        pthread_mutex_lock(&philosopher->conf->mutex);
        print_status("has taken a fork", philosopher->number + 1);
        pthread_mutex_unlock(&philosopher->conf->mutex);
        eating(philosopher, conf->time_to_eat);
        pthread_mutex_unlock(second);
        pthread_mutex_unlock(first);
        sleeping(philosopher);
    }
}

void init(t_philosopher *philosopher_array, pthread_mutex_t *fork_array, t_config *main_conf)
{
    size_t i;
    size_t number_of_philosopher;
    struct timeval last_eating;

    number_of_philosopher = main_conf->number_of_philosopher;
    i = 0;
    while (i < number_of_philosopher) {
        pthread_mutex_init(&fork_array[i], NULL);
        philosopher_array[i].conf = main_conf;
        philosopher_array[i].left = fork_array + i;
        philosopher_array[i].right = i ? fork_array + i - 1 : fork_array + number_of_philosopher - 1;
        philosopher_array[i].number = i;
        philosopher_array[i].state.counter = 0;
        gettimeofday(&last_eating, NULL);
        philosopher_array[i].state.last_eating = last_eating;
        i++;
    }
}

bool timeval_cmp(struct timeval a, struct timeval b) {
    if (a.tv_sec > b.tv_sec) {
        return (true);
    }
    if (a.tv_sec < b.tv_sec) {
        return (false);
    }
    if (a.tv_usec > b.tv_usec) {
        return (true);
    }
    return (false);
}

struct timeval timeval_add(struct timeval a, unsigned int b) {
    struct timeval result;

    result.tv_sec = a.tv_sec + b / 1000;
    result.tv_usec = a.tv_usec + b % 1000 * 1000;
    return (result);
}

void *monitor_run(void *arg) {
    t_philosopher *philosopher_array;
    struct timeval time;
    size_t i;
    size_t number_of_philosopher;
    size_t counter;

    philosopher_array = (t_philosopher *)arg;
    i = 0;
    while (1) {
        counter = 0;
        number_of_philosopher = philosopher_array[i].conf->number_of_philosopher;
        while (i < number_of_philosopher) {
            gettimeofday(&time, NULL);
            if (timeval_cmp(time, timeval_add(philosopher_array[i].state.last_eating, philosopher_array[i].conf->time_to_die))) {
                pthread_mutex_lock(&philosopher_array[i].conf->mutex);
                print_status("died", i + 1);
                return (NULL);
            }
            if (philosopher_array[i].conf->number_of_time_each_philosophers_must_eat >= 0
                 && philosopher_array[i].state.counter >= philosopher_array[i].conf->number_of_time_each_philosophers_must_eat) {
                counter += 1;
            }
            i++;
        }
        i = 0;
        pthread_mutex_lock(&philosopher_array[i].conf->mutex);
        if (counter == number_of_philosopher) {
            return (NULL);
        }
        pthread_mutex_unlock(&philosopher_array[i].conf->mutex);
    }
}

int main(int ac, char** av) {
	t_config conf;
	pthread_mutex_t *fork_array;
	t_philosopher *philosopher_array;
	pthread_t monitor;
	size_t i;

	if (config(&conf, ac, av)) {
		return (EXIT_FAILURE);
	}
	if (!(fork_array = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * conf.number_of_philosopher))) {
        return (EXIT_FAILURE);
    }
    if (!(philosopher_array = (t_philosopher *)malloc(sizeof(*philosopher_array) * conf.number_of_philosopher))) {
        free(fork_array);
        return (EXIT_FAILURE);
    }
	init(philosopher_array, fork_array, &conf);
	i = 0;
	while (i < conf.number_of_philosopher) {
	    pthread_create(&philosopher_array[i].thread, NULL, &philosopher_run, &philosopher_array[i]);
	    i++;
	}
	i = 0;
    while (i < conf.number_of_philosopher) {
        pthread_detach(philosopher_array[i].thread);
        i++;
    }
    pthread_create(&monitor, NULL, &monitor_run, philosopher_array);
    pthread_join(monitor, NULL);
	return (EXIT_SUCCESS);
}
