/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaabid <slaabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:24:21 by slaabid           #+#    #+#             */
/*   Updated: 2026/02/24 13:31:44 by slaabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_newlst(int value, t_list **stack_a)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		error_exit(stack_a);
	new->value = value;
	new->next = NULL ;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*last;

	if (!lst || !newlst)
		return ;
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

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
