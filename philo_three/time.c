#include <sys/time.h>
#include <stdbool.h>
#include <stdlib.h>

uint64_t        timeval_to_msec(struct timeval time) {
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

bool            timeval_cmp(struct timeval a, struct timeval b) {
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

struct timeval  timeval_add(struct timeval a, unsigned int b) {
    struct timeval result;

    result.tv_sec = a.tv_sec + b / 1000;
    result.tv_usec = a.tv_usec + b % 1000 * 1000;
    return (result);
}
