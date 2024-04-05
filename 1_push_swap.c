/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   1_push_swap.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 12:25:12 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/15 18:30:58 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		stack_size;

	stack_b = NULL;
	presort_and_index(stack_a);
	stack_size = ft_stack_size(*stack_a);
	if (stack_size <= 5)
		sort_small_stack(stack_a, &stack_b, stack_size);
	else
		radix_sort(stack_a, &stack_b);
}

void	handle_error(t_stack **stack)
{
	if (stack != NULL)
		free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	if (argc < 2 || (argc == 2 && (argv[1][0] == '\0')))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (input_check(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	stack = convert_input(argc, argv);
	if (stack == NULL)
		handle_error(&stack);
	if (is_sorted(stack, 'a') == 0)
	{
		free_stack(&stack);
		return (0);
	}
	push_swap(&stack);
	free_stack(&stack);
	return (0);
}
