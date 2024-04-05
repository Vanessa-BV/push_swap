/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 12:25:58 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/14 15:19:09 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = ft_stack_new(stack->number);
	if (temp == NULL)
		return (NULL);
	stack = stack->next;
	while (stack != NULL)
	{
		temp2 = ft_stack_new(stack->number);
		if (temp2 == NULL)
		{
			free(temp);
			return (NULL);
		}
		ft_stack_add_back(&temp, temp2);
		stack = stack->next;
	}
	return (temp);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = NULL;
	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

int	ft_stack_size(t_stack *stack)
{
	int		len;

	len = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	ft_stack_add_front(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}

long long	ft_atoll(const char *str)
{
	long long	number;
	int			neg_vs_pos;
	int			i;

	neg_vs_pos = 1;
	i = 0;
	number = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg_vs_pos = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * neg_vs_pos);
}
