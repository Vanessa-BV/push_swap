/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   2_input_check.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 12:25:20 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/12 12:25:20 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_check(int argc, char **argv)
{
	int			i;
	long long	temp;
	char		**str;

	i = 0;
	if (argc == 2)
		str = ft_split(argv[1], ' ');
	else
		str = argv + 1;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		temp = ft_atoll(str[i]);
		if ((temp < INT_MIN || temp > INT_MAX) || digit_check(str[i]) == -1)
		{
			if (argc == 2)
				free_array(str);
			return (-1);
		}
		i++;
	}
	if (argc == 2)
		free_array(str);
	return (0);
}

int	duplicate_check(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;

	current = stack;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->number == temp->number)
				return (-1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}

int	digit_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array != NULL && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
