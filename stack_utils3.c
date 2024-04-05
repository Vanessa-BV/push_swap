/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils3.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/16 15:45:56 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/16 15:45:56 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	if (temp == NULL)
		return ;
	while (temp != NULL)
	{
		temp->current_index = i;
		temp = temp->next;
		i++;
	}
}

t_stack	*min_node(t_stack *stack)
{
	int		min;
	t_stack	*temp;

	min = stack->number;
	temp = stack;
	while (stack != NULL)
	{
		if (stack->number < min)
			min = stack->number;
		stack = stack->next;
	}
	while (temp != NULL)
	{
		if (temp->number == min)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

t_stack	*max_node(t_stack *stack)
{
	int		max;
	t_stack	*temp;

	max = stack->number;
	temp = stack;
	while (stack != NULL)
	{
		if (stack->number > max)
			max = stack->number;
		stack = stack->next;
	}
	while (temp != NULL)
	{
		if (temp->number == max)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
