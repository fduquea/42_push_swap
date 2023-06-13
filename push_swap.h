/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:18:04 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/12 23:29:21 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				price;
	int				position;
	bool			cheapest;
	int				half;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// Main
int				main(int argc, char **argv);

// stack_split create_stack_errors

char			**ft_split(char *str, char c);
void			create_stack(t_stack **a, char **args, int argc);
void			free_fake_argv(char **args);
void			stack_free(t_stack **a);
int				check_repetition(t_stack *a, int n);
int				error_syntax(char *str);
void			stack_error(t_stack **a, char **args, int argc);

// create_stack
void			create_stack(t_stack **a, char **args, int argc);
void			add_single_number(t_stack **stack, int num);
t_stack			*find_last_node(t_stack *node);
long			ft_atol(const char *str);

// set_stuff
void			set_stuff(t_stack *a, t_stack *b);
void			set_cheapest(t_stack *b);
void			set_prices(t_stack *a, t_stack *b);
void			set_positions(t_stack *stack);
void			set_targets(t_stack *a, t_stack *b);

// Command_utils
t_stack			*return_cheapest(t_stack *stack);
int				stack_len(t_stack *a);
t_stack			*last_node(t_stack *stack);
t_stack			*smallest(t_stack *stack);
t_stack			*biggest(t_stack *stack);

// algorithm
void			move_one(t_stack **a, t_stack **b);
void			finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);
void			reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void			rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void			ft_push_swap(t_stack **a, t_stack **b);

// func alg utils
void			sort_three(t_stack **a);
void			sort_five(t_stack **a, t_stack **b);
int				is_sorted(t_stack *a);



// The subject commands

void			swap(t_stack **stack);
void			sa(t_stack **stack);
void			sb(t_stack **stack);
void			ss(t_stack **a, t_stack **b);

void			push(t_stack **dest, t_stack **src);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **b, t_stack **a);

void			rotate(t_stack **stack);
void			ra(t_stack **stack);
void			rb(t_stack **stack);
void			rr(t_stack **a, t_stack **b);

void			reverse(t_stack **stack);
void			rra(t_stack **stack);
void			rrb(t_stack **stack);
void			rrr(t_stack **a, t_stack **b);

#endif // PUSH_SWAP_H