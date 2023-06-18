/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:18:04 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/18 01:48:48 by fduque-a         ###   ########.fr       */
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
	int				final_index;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// free_error_check
void	free_fake_argv(char **argv);
void	stack_free(t_stack **a);
int		check_repetion(t_stack *a, int n);
int		error_syntax(char *str);
void	stack_error(t_stack **a, char **args, int argc, bool status);

//setters//
void	set_stuff(t_stack *a, t_stack *b);//
void	set_cheapest(t_stack *b);//
void	set_prices(t_stack *a, t_stack *b);//
void	set_positions(t_stack *stack);//
void	set_targets(t_stack *a, t_stack *b);//

// push_swap // 
void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);//
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);//
void	move_one(t_stack **a, t_stack **b);//
void	push_swap(t_stack **a, t_stack **b);//

// sort utils //
t_stack	*return_cheapest(t_stack *stack);
int		max_value(int a, int b);
void	get_final_index(t_stack *a, int size);
void	push_to_b(t_stack **a, t_stack **b, int size);
long	ft_atol(const char *str);

// small sort // 
void	sort_five(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);

// stack creation //
void	add_number(t_stack **stack, int num); //
void	create_stack(t_stack **a, char **argv, int argc, bool status); //
int		is_sorted(t_stack *a); //

// main //
int		ft_strchr(char *s, int c); //
char	**ft_split(char *str, char c); //
int		main(int argc, char **argv); //

//utils_algo //
t_stack	*smallest_node(t_stack *stack); //
t_stack	*biggest_node(t_stack *stack); //
int		stack_len(t_stack *a); //
t_stack	*last_node(t_stack *stack); //
t_stack	*findlast_node(t_stack *node); //

//comm swap //
void	swap(t_stack **stack);
void	sa(t_stack **stack, bool status);
void	sb(t_stack **stack, bool status);
void	ss(t_stack **a, t_stack **b, bool status);

//comm push //
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b, bool status);
void	pb(t_stack **b, t_stack **a, bool status);

//comm rotate //
void	rotate(t_stack **stack);
void	ra(t_stack **stack, bool status);
void	rb(t_stack **stack, bool status);
void	rr(t_stack **a, t_stack **b, bool status);

//comm reverse //
void	reverse(t_stack **stack);
void	rra(t_stack **stack, bool status);
void	rrb(t_stack **stack, bool status);
void	rrr(t_stack **a, t_stack **b, bool status);

#endif // PUSH_SWAP_H