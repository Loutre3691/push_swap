// #include <push_swap.h>
#include <stdio.h>

long	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	} 
	return (res * sign);
}
int     ft_isnumber(char *str)
{
    int i;

    i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (str[i] == '\0')
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
int main(int argc, char **argv)
{
    int i = 1;
    if (argc < 2)
        return (0);
    while (i < argc)
    {
        if (!ft_isnumber(argv[i]))
        {    
            (printf("Error"));
            return(1);    
        }
        printf("%ld\n", ft_atoi(argv[i]));
        i++;
    }
    return(0);
}