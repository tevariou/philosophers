/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:49:23 by triou             #+#    #+#             */
/*   Updated: 2020/08/02 21:49:24 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdint.h>
#include <unistd.h>

uint64_t		timeval_to_msec(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

uint64_t 		timeval_cmp(struct timeval a, struct timeval b)
{
	if (a.tv_sec > b.tv_sec)
		return ((a.tv_sec - b.tv_sec) * 1000);
	if (a.tv_sec < b.tv_sec)
		return ((a.tv_sec - b.tv_sec) * 1000);
	if (a.tv_usec / 1000 > b.tv_usec / 1000)
		return ((a.tv_usec - b.tv_usec) / 1000);
	if (a.tv_usec / 1000 < b.tv_usec / 1000)
		return ((a.tv_usec - b.tv_usec) / 1000);
	return (0);
}

struct timeval	timeval_add(struct timeval a, unsigned int b)
{
	uint64_t		time;
	struct timeval	result;

	time = (a.tv_usec + b * 1000) / 1000000;
	result.tv_sec = a.tv_sec + time;
	time = (a.tv_usec + b * 1000) % 1000000;
	result.tv_usec = time;
	return (result);
}

void			ft_sleep(int msec)
{
	struct timeval	start;
	struct timeval	now;
	unsigned int	res;

	gettimeofday(&start, NULL);
	now = start;
	res = 0;
	while (res < (unsigned int)msec)
	{
		usleep(500);
		gettimeofday(&now, NULL);
		res = timeval_to_msec(now) - timeval_to_msec(start);
	}
}
