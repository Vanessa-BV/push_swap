/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   2.1_convert_input.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 12:25:16 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/12 12:25:16 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*convert_input(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc == 2)
		stack_a = single_arg_input(argv[1]);
	else
		stack_a = multi_arg_input(argv);
	if (stack_a == NULL)
		return (NULL);
	if (duplicate_check(stack_a) == -1)
		handle_error(&stack_a);
	return (stack_a);
}

t_stack	*single_arg_input(char *string)
{
	char		**temp;
	t_stack		*stack_a;
	t_stack		*new_node;
	long		i;
	long long	number;

	stack_a = NULL;
	temp = ft_split(string, ' ');
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (temp[i] != NULL)
	{
		number = ft_atoll(temp[i]);
		if (number == 0 && ft_strncmp(temp[i], "0", 1) != 0)
			return (free_array(temp), NULL);
		new_node = ft_stack_new(number);
		if (new_node == NULL)
			return (free_array(temp), NULL);
		ft_stack_add_back(&stack_a, new_node);
		i++;
	}
	return (free_array(temp), stack_a);
}

t_stack	*multi_arg_input(char **argv)
{
	long		i;
	t_stack		*new_node;
	t_stack		*stack_a;
	long long	number;

	i = 1;
	stack_a = NULL;
	while (argv[i] != NULL)
	{
		number = ft_atoll(argv[i]);
		if (number == 0 && ft_strncmp(argv[i], "0", 1) != 0)
			return (NULL);
		new_node = ft_stack_new(number);
		if (new_node == NULL)
			return (NULL);
		ft_stack_add_back(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}
