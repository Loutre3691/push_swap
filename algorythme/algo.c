#include "push_swap.h"

void    ft_algo(t_list **stack_a, t_list **stack_b)
{
    int size;

    size = stack_size(*stack_a);
    if (stack_size <= 3)
        ft_simple_algo(stack_a, stack_b);
    else if (stack_size <= 5)
        ft_medium_algo(stack_a, stack_b);
    else
        ft_complex_algo(stack_a, stack_b);
}