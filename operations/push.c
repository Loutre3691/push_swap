/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: slaabid <slaabid@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/01/23 20:49:29 by slaabid		   #+#	#+#			 */
/*   Updated: 2026/02/23 22:07:33 by slaabid		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*temp;

	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	bench->pb++;
	bench->total++;
	if (!bench->active)
		write(1, "pb\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*temp;

	if (!stack_b || !*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	bench->pa++;
	bench->total++;
	if (!bench->active)
		write(1, "pa\n", 3);
}
