/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaabid <slaabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:07:23 by slaabid           #+#    #+#             */
/*   Updated: 2026/01/29 12:03:41 by slaabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_list **stack_a)
{
    t_list *prev;
    t_list *last;

    if (!stack_a || !*stack_a || (*stack_a)->next)
        return;

    prev = NULL;
    last = *stack_a;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    if (prev)
        prev->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    write(1, "rra\n", 4);
}
void rrb(t_list **stack_b)
{
    t_list *prev;
    t_list *last;

    if (!stack_b || !*stack_b || (*stack_b)->next)
        return;
    prev = NULL;
    last = *stack_b;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    if (prev)
        prev->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    write(1, "rrb\n", 4);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    write(1, "rrr\n", 4);
}