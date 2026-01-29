#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    t_list *stack_a = NULL;
    // t_list *stack_b = NULL;
    
    ft_parsing(&stack_a, argc, argv);
    index_stack(&stack_a);
    print_stack(stack_a);
    if (is_sorted(stack_a))
    {
        write(1, "Stack is already sorted.\n", 26);
        free_stack(&stack_a);
        return (0);
    }
}