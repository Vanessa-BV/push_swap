/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_rotate.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*	                                                 +#+                      */
/*   Created: 2024/03/12 12:25:44 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/14 14:21:46 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, char operation)
{
	t_stack	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	ft_stack_add_back(stack, first);
	if (operation == 'a')
		ft_printf("ra\n");
	else if (operation == 'b')
		ft_printf("rb\n");
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, '\0');
	rotate(stack_b, '\0');
	ft_printf("rr\n");
}

void	reverse_rotate(t_stack **stack, char operation)
{
	t_stack	*last;
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = ft_stack_last(*stack);
	temp = *stack;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *stack;
	*stack = last;
	if (operation == 'a')
		ft_printf("rra\n");
	else if (operation == 'b')
		ft_printf("rrb\n");
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, '\0');
	reverse_rotate(stack_b, '\0');
	ft_printf("rrr\n");
}
