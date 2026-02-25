/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   small_sort.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: slaabid <slaabid@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/01/29 12:50:57 by slaabid		   #+#	#+#			 */
/*   Updated: 2026/02/23 22:16:22 by slaabid		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack_a, t_bench *bench)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, bench);
}

void	sort_three(t_list **stack_a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first < second && second < third)
		return ;
	else if (first > second && second < third && first < third)
		sa(stack_a, bench);
	else if (first > second && second > third)
	{
		sa(stack_a, bench);
		rra(stack_a, bench);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a, bench);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a, bench);
		ra(stack_a, bench);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a, bench);
}

void	sort_four(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0)
			pb(stack_a, stack_b, bench);
		else
			ra(stack_a, bench);
	}
	sort_three(stack_a, bench);
	pa(stack_a, stack_b, bench);
}

void	sort_five(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			pb(stack_a, stack_b, bench);
		else
			ra(stack_a, bench);
	}
	sort_three(stack_a, bench);
	if (*stack_b && (*stack_b)->next
		&& (*stack_b)->index < (*stack_b)->next->index)
		sb(stack_b, bench);
	pa(stack_a, stack_b, bench);
	pa(stack_a, stack_b, bench);
}
