#include <sys/time.h>
#include <stdbool.h>
#include <stdlib.h>

uint64_t        timeval_to_msec(struct timeval time) {
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int             timeval_cmp(struct timeval a, struct timeval b) {
    if (a.tv_sec > b.tv_sec)
        return (1);
    if (a.tv_sec < b.tv_sec)
        return (-1);
    if (a.tv_usec > b.tv_usec)
        return (1);
    if (a.tv_usec < b.tv_usec)
        return (-1);
    return (0);
}

struct timeval  timeval_add(struct timeval a, unsigned int b)
{
    uint64_t        time;
    struct timeval result;

    time = (a.tv_usec + b * 1000) / 1000000;
    result.tv_sec = a.tv_sec + time;
    time = (a.tv_usec + b * 1000) % 1000000;
    result.tv_usec = time;
    return (result);
}

bool            is_timeval(struct timeval time)
{
    return (time.tv_sec || time.tv_usec);
}