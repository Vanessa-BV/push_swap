/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 12:25:50 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/15 18:37:52 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "Libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				number;
	int				sorted_index;
	int				current_index;
	struct s_stack	*next;
}	t_stack;

int			main(int argc, char **argv);
void		push_swap(t_stack **stack_a);
void		handle_error(t_stack **stack);

// Converting the argument input into a stack
t_stack		*convert_input(int argc, char **argv);
long long	ft_atoll(const char *str);
t_stack		*single_arg_input(char *str);
t_stack		*multi_arg_input(char **argv);

// Input checking - numbers, duplicates, and digit size
int			input_check(int argc, char **argv);
int			duplicate_check(t_stack *stack);
int			digit_check(char *str);
void		free_array(char **array);

// Pre-sorting the stack and assigning indexes to stack_a->sorted_index
void		presort_and_index(t_stack **stack_a);
void		index_stack(t_stack **stack_a, t_stack *temp);
int			is_sorted(t_stack *stack, char stack_name);
t_stack		*pre_sort(t_stack **temp);

// Sorting a small stack (size: <= 5)
void		sort_small_stack(t_stack **stack_a, t_stack **stack_b, \
			int stack_size);
void		sort_three_a(t_stack **stack);
void		sort_four_a(t_stack **stack_a, t_stack **stack_b);
void		sort_five_a(t_stack **stack_a, t_stack **stack_b);
t_stack		*get_second_min(t_stack *stack, t_stack	*min);

// Sorting a large stack (size: > 5)
void		radix_sort(t_stack **stack_a, t_stack **stack_b);
int			calculate_bits(int max_index);

// Sorting utils
t_stack		*min_node(t_stack *stack);
t_stack		*max_node(t_stack *stack);
void		current_index(t_stack **stack);

// Stack Utils
t_stack		*ft_stack_new(long long number);
void		ft_stack_add_back(t_stack **stack, t_stack *new);
void		ft_print_stack(t_stack *stack);
t_stack		*ft_stack_last(t_stack *stack);
void		free_stack(t_stack **stack);
t_stack		*copy_stack(t_stack *stack);
int			ft_stack_size(t_stack *stack);
void		ft_stack_add_front(t_stack **stack, t_stack *new);

/* Sorting operations */
// rotate and reverse rotate
void		rotate(t_stack **stack, char operation);
void		rotate_both(t_stack **stack_a, t_stack **stack_b);
void		reverse_rotate(t_stack **stack, char operation);
void		reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

// swap
void		swap(t_stack **stack, char operation);
void		swap_both(t_stack **stack_a, t_stack **stack_b);

// swap
void		push(t_stack **pusher, t_stack **receiver, char operation);

#endif