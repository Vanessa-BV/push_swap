/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4_sort_small_stack.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 12:25:28 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/12 12:25:28 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2)
		swap(stack_a, 'a');
	else if (stack_size == 3)
		sort_three_a(stack_a);
	else if (stack_size == 4)
		sort_four_a(stack_a, stack_b);
	else if (stack_size == 5)
		sort_five_a(stack_a, stack_b);
}

void	sort_three_a(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->number;
	second = (*stack)->next->number;
	third = (*stack)->next->next->number;
	if (first > second && second > third)
	{
		rotate(stack, 'a');
		swap(stack, 'a');
	}
	else if (first > second && second < third && first > third)
		rotate(stack, 'a');
	else if (first < second && second > third && third > first)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (first > second && second < third && third > first)
		swap(stack, 'a');
	else if (first < second && second > third && third < first)
		reverse_rotate(stack, 'a');
}

void	sort_four_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		half_stack;

	half_stack = 2;
	current_index(stack_a);
	min = min_node(*stack_a);
	while (min != *stack_a)
	{
		if (min->current_index <= half_stack - 1)
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
	}
	push(stack_a, stack_b, 'b');
	sort_three_a(stack_a);
	push(stack_b, stack_a, 'a');
}

void	sort_five_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	t_stack	*second_min;

	min = min_node(*stack_a);
	second_min = get_second_min(*stack_a, min);
	while (ft_stack_size(*stack_a) > 4)
	{
		if (min->current_index <= 2 || min->current_index <= 2)
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
		if (*stack_a == min || *stack_a == second_min)
			push(stack_a, stack_b, 'b');
	}
	sort_four_a(stack_a, stack_b);
	push(stack_b, stack_a, 'a');
	if ((*stack_a)->number > (*stack_a)->next->number)
		swap(stack_a, 'a');
}

t_stack	*get_second_min(t_stack *stack, t_stack	*min)
{
	t_stack	*temp;
	t_stack	*second_min;

	second_min = max_node(stack);
	temp = stack;
	while (temp != NULL)
	{
		if (temp->number > min->number && temp->number < second_min->number)
			second_min = temp;
		temp = temp->next;
	}
	return (second_min);
}
