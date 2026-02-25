/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   swap.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: slaabid <slaabid@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/01/23 20:44:03 by slaabid		   #+#	#+#			 */
/*   Updated: 2026/02/23 22:18:16 by slaabid		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, t_bench *bench)
{
	t_list	*first;
	t_list	*second;

	if (!stack_a || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	bench->sa++;
	bench->total++;
	if (!bench->active)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, t_bench *bench)
{
	t_list	*first;
	t_list	*second;

	if (!stack_b || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	bench->sb++;
	bench->total++;
	if (!bench->active)
		write(1, "sb\n", 3);
}

void	sa_op(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (!stack_a || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	sb_op(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	if (!stack_b || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	sa_op(stack_a);
	sb_op(stack_b);
	bench->ss++;
	bench->total++;
	if (!bench->active)
		write(1, "ss\n", 3);
}
