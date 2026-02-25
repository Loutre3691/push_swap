/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   medium_sort.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: slaabid <slaabid@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/21 01:39:03 by slaabid		   #+#	#+#			 */
/*   Updated: 2026/02/23 15:27:40 by slaabid		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

static int	chunk_size(int n)
{
	if (n <= 100)
		return ((int)sqrt((double)n));
	return (n / 7);
}

static int	find_max_in_b(t_list *stack_b)
{
	int	max;
	int	max_pos;
	int	i;

	max = stack_b->index;
	max_pos = 0;
	i = 0;
	while (stack_b)
	{
		if (stack_b->index > max)
		{
			max = stack_b->index;
			max_pos = i;
		}
		stack_b = stack_b->next;
		i++;
	}
	return (max_pos);
}

static void	push_chunk_to_b(t_sort *s, int min, int max)
{
	int	size;
	int	i;

	size = ft_lstsize(*s->a);
	i = 0;
	while (*s->a)
	{
		if ((*s->a)->index >= min && (*s->a)->index < max)
		{
			pb(s->a, s->b, s->bench);
			size--;
			i = 0;
		}
		else
		{
			ra(s->a, s->bench);
			if (++i >= size)
				break ;
		}
	}
}

static void	push_max_to_a(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	max_pos;
	int	size;

	while (*stack_b)
	{
		size = ft_lstsize(*stack_b);
		max_pos = find_max_in_b(*stack_b);
		if (max_pos <= size / 2)
			while (max_pos-- > 0)
				rb(stack_b, bench);
		else
		{
			max_pos = size - max_pos;
			while (max_pos-- > 0)
				rrb(stack_b, bench);
		}
		pa(stack_a, stack_b, bench);
	}
}

void	medium_sort(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int		n;
	int		chunk;
	int		min;
	t_sort	s;

	if (simple_small_cases(stack_a, stack_b, bench))
		return ;
	s.a = stack_a;
	s.b = stack_b;
	s.bench = bench;
	n = ft_lstsize(*stack_a);
	chunk = chunk_size(n);
	min = 0;
	while (min < n)
	{
		push_chunk_to_b(&s, min, min + chunk);
		min += chunk;
	}
	push_max_to_a(stack_a, stack_b, bench);
}
