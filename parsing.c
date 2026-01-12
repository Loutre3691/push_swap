// #include <push_swap.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int     has_duplicate(int nb, int* tab)
{
    int i;

    i = 1;
    while (i < tab)
    {
        if (nb == tab[i])
            error_exit();
        i++;
    }
    return(1);
}
long	ft_atoi(const char *nptr)
{
	int	    i;
	int	    sign;
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
    int     i;
    long    *tab;

    i = 0;
    if (argc < 2)
        return (0);
    tab = malloc(sizeof(long) * (argc - 1));
    if (!tab)
        return (1);
    while (i < argc - 1)
    {
        if (!ft_isnumber(argv[i + 1]))
            error_exit();//permet de stopper le programme si av pa valide

        tab[i] = ft_atoi(argv[i + 1]);
        if (tab[i] < -2147483648 || tab[i] > 2147483647)
            error_exit();
        // printf("argv[%d] = %ld\n", i, tab[i]); 
        i++;
    }
    if (has_duplicate(tab[i], &argc - 1))
        printf("argv[%d] = %ld\n", i, tab[i]); 

    return(0);
}