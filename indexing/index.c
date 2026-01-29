/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaabid <slaabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:11:59 by slaabid           #+#    #+#             */
/*   Updated: 2026/01/23 14:23:01 by slaabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_list *stack)
{
    int i;
    
    i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}

void    stack_to_array(t_list *stack, int *array)
{
    int i;

    i = 0;
    while (stack)
    {
        array[i++] = stack->value;
        stack = stack->next;
    }
}
void sort_array(int *array, int size)
{
    int i, j, tmp;
    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (array[i] > array[j])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

void assign_index(t_list *stack, int *array, int size)
{
    int i;

    while (stack)
    {
        i = 0;
        while (i < size)
        {
            if (stack->value == array[i])
            {
                stack->index = i;
                break;
            }
            i++;
        }
        stack = stack->next;
    }
}
void index_stack(t_list **stack)
{
    int size;
    int *array;

    size = stack_size(*stack);
    array = malloc(sizeof(int) * size);
    if (!array)
        error_exit(stack);

    stack_to_array(*stack, array);
    sort_array(array, size);
    assign_index(*stack, array, size);
    free(array);
}
