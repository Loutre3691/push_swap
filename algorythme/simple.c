#include "push_swap.h"

void    ft_simple_algo(t_list **stack_a, t_list **stack_b)
{
    int a;
    int b; 
    int c;
    int size;

    size = size_stack(*stack_a);
    a = (*stack_a)->value;
    b = (*stack_a)->next->value;
    c = (*stack_a)->next->next->value;

    if (size == 2)
    {
        if (a > b)
            ft_sa(stack_a);
        else
            return;
    }
    if (size == 3)
    {
        if (a < b && b < c)
            return;
        else
        {
            if (a > b && c > a)
                ft_sa(stack_a);
            else if (a > b && b > c)
            {
                ft_sa(stack_a);
                ft_rra(stack_a);
            }
            else if (a > b && c > b)
                ft_ra(stack_a);
            else if (a < b && b > c)
            {
                ft_sa(stack_a);
                ft_ra(stack_a);
            }
            else 
                ft_rra(stack_a);
        }
    }

}
