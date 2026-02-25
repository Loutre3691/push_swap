/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   simple_sort.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: slaabid <slaabid@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/18 23:25:35 by slaabid		   #+#	#+#			 */
/*   Updated: 2026/02/23 22:14:04 by slaabid		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_list *stack_a)
{
	int	max;
	int	pos;
	int	i;

	max = stack_a->index;
	pos = 0;
	i = 0;
	while (stack_a)
	{
		if (stack_a->index > max)
		{
			max = stack_a->index;
			pos = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (pos);
}

static void	push_max_to_b(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	size;
	int	max_pos;

	while (*stack_a)
	{
		size = ft_lstsize(*stack_a);
		max_pos = find_max_pos(*stack_a);
		if (max_pos <= size / 2)
			while (max_pos-- > 0)
				ra(stack_a, bench);
		else
		{
			max_pos = size - max_pos;
			while (max_pos-- > 0)
				rra(stack_a, bench);
		}
		pb(stack_a, stack_b, bench);
	}
}

int	simple_small_cases(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	size;

	if (is_sorted(*stack_a))
		return (1);
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sort_two(stack_a, bench);
	else if (size == 3)
		sort_three(stack_a, bench);
	else if (size == 4)
		sort_four(stack_a, stack_b, bench);
	else if (size == 5)
		sort_five(stack_a, stack_b, bench);
	else
		return (0);
	return (1);
}

void	simple_sort(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	if (simple_small_cases(stack_a, stack_b, bench))
		return ;
	push_max_to_b(stack_a, stack_b, bench);
	while (*stack_b)
	{
		pa(stack_a, stack_b, bench);
	}
}
