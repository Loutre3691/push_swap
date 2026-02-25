/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   complexe_sort.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: slaabid <slaabid@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/21 01:55:09 by slaabid		   #+#	#+#			 */
/*   Updated: 2026/02/23 22:13:30 by slaabid		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int n)
{
	int	max;
	int	bits;

	max = n - 1;
	bits = 0;
	while ((1 << bits) <= max)
		bits++;
	return (bits);
}

static void	radix_pass(t_sort *s, int bit, int size)
{
	int	i;
	int	pushed;

	pushed = 0;
	i = 0;
	while (i < size)
	{
		if (((*s->a)->index >> bit) & 1)
			ra(s->a, s->bench);
		else
		{
			pb(s->a, s->b, s->bench);
			pushed++;
		}
		i++;
	}
	while (pushed-- > 0)
		pa(s->a, s->b, s->bench);
}

void	complex_sort(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int		size;
	int		max_bits;
	int		bit;
	t_sort	s;

	if (simple_small_cases(stack_a, stack_b, bench))
		return ;
	s.a = stack_a;
	s.b = stack_b;
	s.bench = bench;
	size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		radix_pass(&s, bit, size);
		bit++;
	}
}
