/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3_pre_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 12:25:23 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/13 19:20:46 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	presort_and_index(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*sorted_temp;

	temp = copy_stack(*stack_a);
	if (temp == NULL)
		handle_error(stack_a);
	sorted_temp = pre_sort(&temp);
	index_stack(stack_a, sorted_temp);
	free_stack(&sorted_temp);
	free_stack(&temp);
}

t_stack	*pre_sort(t_stack **temp)
{
	t_stack	*temp2;
	t_stack	*sorted_temp;
	int		placeholder;

	sorted_temp = *temp;
	while (*temp != NULL)
	{
		temp2 = (*temp)->next;
		while (temp2 != NULL)
		{
			if ((*temp)->number > temp2->number)
			{
				placeholder = (*temp)->number;
				(*temp)->number = temp2->number;
				temp2->number = placeholder;
			}
			temp2 = temp2->next;
		}
		*temp = (*temp)->next;
	}
	return (sorted_temp);
}

void	index_stack(t_stack **stack_a, t_stack *sorted_temp)
{
	int		i;
	t_stack	*original_stack;
	t_stack	*temp;

	original_stack = *stack_a;
	while (original_stack != NULL)
	{
		i = 0;
		temp = sorted_temp;
		while (temp != NULL)
		{
			if (original_stack->number == temp->number)
			{
				original_stack->sorted_index = i;
				break ;
			}
			i++;
			temp = temp->next;
		}
		original_stack = original_stack->next;
	}
}
