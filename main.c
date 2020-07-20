#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define ARG_ERROR "Argument error \n"
#define USAGE "Usage \n"

typedef enum {
	EATING,
	THINKING,
	SLEEPING
} e_state;

typedef struct s_philosopher {
	unsigned int id;
	pthread_t thread;
	e_state state;
	bool left, right;
} t_philosopher;

typedef struct s_config {
	unsigned int number_of_philosopher;
	struct timeval time_to_die;
	struct timeval time_to_eat;
	struct timeval time_to_sleep;
	unsigned int number_of_time_each_philosophers_must_eat;
} t_config;


void usage() {
	printf(USAGE);
}

typedef struct s_table {
	t_philosopher philosopher;
	struct s_table *prev;
	struct s_table *next;
} t_table;

struct timeval msec_to_timeval (int msec) {
	struct timeval time;

	time.tv_sec = msec / 1000;
	time.tv_usec = msec % 1000 * 1000;
	return time;
}

int init(t_config *conf, int ac, char **av) {
	if (ac < 5) {
		return (1);
	}
	conf->number_of_philosopher = atoi(av[1]);
	conf->time_to_die = msec_to_timeval(atoi(av[2]));
	conf->time_to_eat = msec_to_timeval(atoi(av[3]));
	conf->time_to_sleep = msec_to_timeval(atoi(av[4]));
	if (ac == 6) {
		conf->number_of_time_each_philosophers_must_eat = atoi(av[5]);
	}
	return (0);
}

int errorf(char *error) {
	printf(error);
	return (1);
}

int create_philosophers(t_table *table, t_config *conf) {
	int i;

	i = 0;
	while (i < conf->number_of_philosopher) {

	}
}

int main(int ac, char** av) {
	t_config conf;
	t_table table;

	if (init(&conf, ac, av)) {
		return errorf(ARG_ERROR);
	}

	return (0);
}
