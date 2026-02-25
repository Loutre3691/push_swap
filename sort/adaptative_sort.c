/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   adaptative_sort.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: slaabid <slaabid@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/21 02:40:04 by slaabid		   #+#	#+#			 */
/*   Updated: 2026/02/23 15:20:34 by slaabid		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	double	disorder;

	disorder = calculation_disorder(*stack_a);
	if (disorder < 0.2)
		simple_sort(stack_a, stack_b, bench);
	else if (disorder < 0.5)
		medium_sort(stack_a, stack_b, bench);
	else
		complex_sort(stack_a, stack_b, bench);
}
