/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   bench.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: slaabid <slaabid@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/21 20:44:27 by slaabid		   #+#	#+#			 */
/*   Updated: 2026/02/22 23:54:41 by slaabid		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

static char	*strategy_name(int strategy)
{
	if (strategy == SIMPLE)
		return ("Simple O(n²)");
	else if (strategy == MEDIUM)
		return ("Medium O(n√n)");
	else if (strategy == COMPLEX)
		return ("Complex O(n log n)");
	return ("Adaptive");
}

void	print_bench(t_bench *bench, t_options opts, double disorder)
{
	int	percent;
	int	decimal;

	percent = (int)(disorder * 100);
	decimal = (int)(disorder * 10000) % 100;
	ft_printf_fd(2, "Disorder:   %d.%d%%\n", percent, decimal);
	ft_printf_fd(2, "Strategy:   %s\n", strategy_name(opts.strategy));
	ft_printf_fd(2, "Total ops:  %d\n", bench->total);
	ft_printf_fd(2, "sa:%d sb:%d ss:%d\n", bench->sa, bench->sb, bench->ss);
	ft_printf_fd(2, "pa:%d pb:%d\n", bench->pa, bench->pb);
	ft_printf_fd(2, "ra:%d rb:%d rr:%d\n", bench->ra, bench->rb, bench->rr);
	ft_printf_fd(2, "rra:%d rrb:%d rrr:%d\n", bench->rra, bench->rrb,
		bench->rrr);
}
