/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   rotate.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: slaabid <slaabid@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/01/25 17:05:36 by slaabid		   #+#	#+#			 */
/*   Updated: 2026/02/23 22:08:11 by slaabid		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, t_bench *bench)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack_a);
	last->next = first;
	bench->ra++;
	bench->total++;
	if (!bench->active)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, t_bench *bench)
{
	t_list	*first;
	t_list	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack_b);
	last->next = first;
	bench->rb++;
	bench->total++;
	if (!bench->active)
		write(1, "rb\n", 3);
}

void	ra_op(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack_a);
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb_op(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack_b);
	last->next = first;
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	ra_op(stack_a);
	rb_op(stack_b);
	bench->rr++;
	bench->total++;
	if (!bench->active)
		write(1, "rr\n", 3);
}
