#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

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

short	ft_atos(const char *str)
{
    int		            i;
    unsigned int		number;

    i = 0;
    number = 0;
    while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
           || (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
        i++;
    while ((str[i] >= '0') && (str[i] <= '9'))
    {
        number *= 10;
        number += ((int)str[i] - 48);
        if (number > SHRT_MAX)
            return (-1);
        i++;
    }
    if (str[i] != '\0')
        return (-1);
    return ((short)number);
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

int	    ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_putstr_fd(char const *s, int fd)
{
    if (s)
        write(fd, s, ft_strlen(s));
}

int     error(const char *e)
{
    ft_putstr_fd(e, 2);
    return (EXIT_FAILURE);
}