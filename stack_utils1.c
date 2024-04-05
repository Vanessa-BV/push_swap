/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 12:25:55 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/15 10:56:25 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(long long number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (new == NULL)
		return (NULL);
	new->number = number;
	new->sorted_index = -1;
	new->current_index = -1;
	new->next = NULL;
	return (new);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	temp = ft_stack_last(*stack);
	temp->next = new;
}

void	ft_print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d\n", stack->number);
		stack = stack->next;
	}
}

t_stack	*ft_stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

int	is_sorted(t_stack *stack, char stack_name)
{
	if (stack_name == 'a')
	{
		while (stack != NULL && stack->next != NULL)
		{
			if (stack->number > stack->next->number)
				return (-1);
			stack = stack->next;
		}
	}
	else if (stack_name == 'b')
	{
		while (stack != NULL && stack->next != NULL)
		{
			if (stack->number < stack->next->number)
				return (-1);
			stack = stack->next;
		}
	}
	return (0);
}
