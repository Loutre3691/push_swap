#include "push_swap.h"

t_list	*ft_newlst(int value, t_list **stack_a)
{
    t_list  *new;

    new = malloc(sizeof(t_list));
    if (!new)
        error_exit(stack_a);
    new->value = value;
    new->next = NULL ;
    return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
    t_list *last;

    if (!lst || !newlst)
        return;
    
    if (*lst == NULL)
    {
        *lst = newlst;
        return ;
    }
    last = ft_lstlast(*lst);
    last->next = newlst;
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

// a retirer, juste pour verif :
void print_stack(t_list *stack)
{
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}
