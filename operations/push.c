/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaabid <slaabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:49:29 by slaabid           #+#    #+#             */
/*   Updated: 2026/01/25 19:25:22 by slaabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *temp;

    if (!stack_a || !*stack_a)
        return;
    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = *stack_b;
    *stack_b = temp;
    write(1, "pa\n", 3);
}

void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *temp;

    if (!stack_b || !*stack_b)
        return;

    temp = *stack_b;
    *stack_b = temp->next;
    temp->next = *stack_a;
    *stack_a = temp;

    write(1, "pb\n", 3);
}
