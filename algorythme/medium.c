#include "push_swap.h"

void    ft_medium_algo(char **stack_a, char **stack_b)
{
    int size;
    int a;
    int b; 
    int c;
    int d;
    int e;

    a = (*stack_a)->value;
    b = (*stack_a)->next->value;
    c = (*stack_a)->next->next->value;
    d = (*stack_a)->next->next->next->value;
    e = (*stack_a)->next->next->next->next->value;

    size = stack_size(*stack_a);
    if (size == 4)
    {
        

    }
    else if (size == 5)
    {


    }

}