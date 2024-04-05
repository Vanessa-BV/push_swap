/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   5_radix_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/16 15:43:27 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/16 15:43:27 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_bits(int max_index)
{
	int	max_bits;

	max_bits = 0;
	while (max_index > 0)
	{
		max_index = max_index >> 1;
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_index;
	int	max_bits;
	int	i;
	int	j;
	int	size_a;

	max_index = max_node(*stack_a)->sorted_index;
	max_bits = calculate_bits(max_index);
	i = 0;
	while (i < max_bits)
	{
		size_a = ft_stack_size(*stack_a);
		j = 0;
		while (j < size_a)
		{
			if (((*stack_a)->sorted_index >> i) & 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			j++;
		}
		while (*stack_b != NULL)
			push(stack_b, stack_a, 'a');
		i++;
	}
}
