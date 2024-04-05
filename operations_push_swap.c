/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_push_swap.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/16 15:44:58 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/16 15:44:58 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char operation)
{
	t_stack	*temp;

	temp = (*stack)->next->next;
	ft_stack_add_front(stack, (*stack)->next);
	(*stack)->next->next = temp;
	if (operation == 'a')
		ft_printf("sa\n");
	else if (operation == 'b')
		ft_printf("sb\n");
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, '\0');
	swap(stack_b, '\0');
	ft_printf("ss\n");
}

void	push(t_stack **pusher, t_stack **receiver, char operation)
{
	t_stack	*temp;

	if (*pusher == NULL)
		return ;
	temp = (*pusher)->next;
	(*pusher)->next = NULL;
	ft_stack_add_front(receiver, *pusher);
	*pusher = temp;
	if (operation == 'a')
		ft_printf("pa\n");
	else if (operation == 'b')
		ft_printf("pb\n");
}
