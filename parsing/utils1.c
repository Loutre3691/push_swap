#include "push_swap.h"

int	ft_atoi(const char *nptr, t_list **stack_a)
{
	int	    i;
	int	    sign;
	long	    res;

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
        if (res * sign > INT_MAX || res * sign < INT_MIN)
            error_exit(stack_a);
		i++;
	} 
	return ((int)res * sign);
}

int    has_duplicate(t_list *stack, int value)
{
    while (stack)
    {
        if (stack->value == value) 
            return(1);
        stack = stack->next;
    }
    return(0);
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

int     is_sorted(t_list *stack)
{
    if (!stack)
        return (1);

    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}
