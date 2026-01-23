#include "push_swap.h"

void	error_exit(t_list **stack)
{
	if (stack)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void free_split(char **split)
{
    int i = 0;

    while (split[i])
        free(split[i++]);
    free(split);
}