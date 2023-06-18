/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:18:59 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/17 00:08:11 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Loop decays once
 * 		~cheapest_node tops is a
 * 		~relative target_node tops in b
*/
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b, false);
	set_positions(*a);
	set_positions(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b, false);
	set_positions(*a);
	set_positions(*b);
}

/*
 * Conclude the rotation of the stacks 
*/
void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->half == 1)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->half == 1)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}

/*
 * Move the node from 'b' to 'a'
 * with the metadata available in the node
 * 1)Make the target nodes emerge
 * 2)push in A
*/
void	move_one(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->half == 1 && cheapest->target->half == 1)
		rotate_both(a, b, cheapest);
	else if ((cheapest->half == 0) && (cheapest->target->half == 0))
		reverse_rotate_both(a, b, cheapest);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target, 'a');
	pa(a, b, false);
}

/*
 * ~Push all nodes in B 
 * ~For every configuration choose the "cheapest_node"
 * ~Push everything back in A in order
*/
void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
		push_to_b(a, b, len_a);
	sort_three(a);
	while (*b)
	{
		set_stuff(*a, *b);
		move_one(a, b);
	}
	set_positions(*a);
	smallest = smallest_node(*a);
	if (smallest->half == 1)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
