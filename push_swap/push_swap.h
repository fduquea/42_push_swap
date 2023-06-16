/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:18:04 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/16 22:28:59 by fduque-a         ###   ########.fr       */
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
void			freeFakeArgv(char **args);
void			stackFree(t_stack **a);
int				checkRepetition(t_stack *a, int n);
int				errorSyntax(char *str);
void			stackError(t_stack **a, char **args, int argc);

//setters//
void			setStuff(t_stack *a, t_stack *b);//
void			setCheapest(t_stack *b);//
void			setPrices(t_stack *a, t_stack *b);//
void			setPositions(t_stack *stack);//
void			setTargets(t_stack *a, t_stack *b);//

// push_swap // 
void			finishRotation(t_stack **stack, t_stack *top_node, char stack_name);//
void			reverseRotateBoth(t_stack **a, t_stack **b, t_stack *cheapest);//
void			rotateBoth(t_stack **a, t_stack **b, t_stack *cheapest);//
void			moveOne(t_stack **a, t_stack **b);//
void			pushSwap(t_stack **a, t_stack **b);//

// sort utils //
t_stack			*returnCheapest(t_stack *stack);
int				maxValue(int a, int b);
void			getFinalIndex(t_stack *a, int size);
void			push2B(t_stack **a, t_stack **b, int size);
long			ft_atol(const char *str);

// small sort // 
void			sortFive(t_stack **a, t_stack **b);
void			sortThree(t_stack **a);

// stack creation //
void			addNumber(t_stack **stack, int num); //
void			createStack(t_stack **a, char **args, int argc); //
int				isSorted(t_stack *a); //

// main //
int				ft_strchr(char *s, int c); //
char			**ft_split(char *str, char c); //
int				main(int argc, char **argv); //

//utils_algo //
t_stack			*smallestNode(t_stack *stack); //
t_stack			*biggestNode(t_stack *stack); //
int				stackLen(t_stack *a); //
t_stack			*lastNode(t_stack *stack); //
t_stack			*findLastNode(t_stack *node); //

//comm swap //
void			swap(t_stack **stack);
void			sa(t_stack **stack);
void			sb(t_stack **stack);
void			ss(t_stack **a, t_stack **b);

//comm push //
void			push(t_stack **dest, t_stack **src);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **b, t_stack **a); 

//comm rotate //
void			rotate(t_stack **stack);
void			ra(t_stack **stack);
void			rb(t_stack **stack);
void			rr(t_stack **a, t_stack **b);

//comm reverse //
void			reverse(t_stack **stack);
void			rra(t_stack **stack);
void			rrb(t_stack **stack);
void			rrr(t_stack **a, t_stack **b);

#endif // PUSH_SWAP_H