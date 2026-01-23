#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;
    
    ft_parsing(&stack_a, argc, argv);

    if (stack_a)
        ft_algo(&stack_a, &stack_b);
        

    return(0);
}

