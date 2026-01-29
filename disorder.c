/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaabid <slaabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:53:48 by slaabid           #+#    #+#             */
/*   Updated: 2026/01/27 14:42:57 by slaabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double  calculation_disorder(t_list *stack)
{
    t_list *i;
    t_list *j;
    long mistakes;
    long total_pairs;

    mistakes = 0;
    total_pairs = 0;
    i = stack;

    while(i)
    {
        j = i->next;
        while(j)
        {
            total_pairs++;
            if(i->index > j->index)
                mistakes++;
            j = j->next;
        }
        i = i->next;
    }
    if (total_pairs == 0)
        return 0.0;
    return ((double)mistakes / (double)total_pairs);
}