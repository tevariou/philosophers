#include <unistd.h>

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
