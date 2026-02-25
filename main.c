/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaabid <slaabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:24:42 by slaabid           #+#    #+#             */
/*   Updated: 2026/02/25 10:17:37 by slaabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

static void	run_strategy(t_list **a, t_list **b, t_options opts, t_bench *bench)
{
	if (opts.strategy == SIMPLE)
		simple_sort(a, b, bench);
	else if (opts.strategy == MEDIUM)
		medium_sort(a, b, bench);
	else if (opts.strategy == COMPLEX)
		complex_sort(a, b, bench);
	else
		adaptive_sort(a, b, bench);
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_options	opts;
	t_bench		bench;
	double		disorder;

	stack_a = NULL;
	stack_b = NULL;
	bench = (t_bench){0};
	if (argc < 2)
		return (0);
	opts = parse_options(&argc, argv);
	bench.active = opts.bench;
	ft_parsing(&stack_a, argc, argv);
	index_stack(&stack_a);
	if (is_sorted(stack_a))
		return (free_stack(&stack_a), 0);
	disorder = calculation_disorder(stack_a);
	run_strategy(&stack_a, &stack_b, opts, &bench);
	if (opts.bench)
		print_bench(&bench, opts, disorder);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
