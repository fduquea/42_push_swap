/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_set_stuff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:00:43 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/12 23:26:43 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_targets(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*curr_a;
	int		best_match;
	
	while(b)
	{
		best_match = INT_MAX;
		curr_a = a;
		while(curr_a)
		{
			if (curr_a->data > b->data && curr_a->data < best_match)
			{
				target = curr_a;
				best_match = curr_a->data;
			}
			curr_a = curr_a->next;
		}
		if (best_match == INT_MAX)
			b->target = smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_positions(t_stack *stack)
{
	int	i;
	int	center;
	
	if (stack == NULL)
		return ;
	center = stack_len(stack) / 2;
	i = 0;
	while(stack)
	{
		stack->position = i;
		if (i <= center)
			stack->half = 1;
		else
			stack->half = 0; 
		i++;
		stack = stack->next;
	}
}

void	set_prices(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->price = b->position;
		if (b->half == 0)
			b->price = len_b - (b->position);
		if (b->target->half == 1)
			b->price += b->target->position;
		else
			b->price += len_a - (b->target->position);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	int		best_match_data;
	t_stack	*best_match_node;

	if (NULL == b)
		return ;
	best_match_data = INT_MAX;
	while (b)
	{
		if (b->price < best_match_data)
		{
			best_match_data = b->price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	set_stuff(t_stack *a, t_stack *b)
{
	set_positions(a);
	set_positions(b);
	set_targets(a, b);
	set_prices(a, b);
	set_cheapest(b);
}