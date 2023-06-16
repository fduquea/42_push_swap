/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:18:59 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/16 22:29:48 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Loop decays once
 * 		~cheapest_node tops is a
 * 		~relative target_node tops in b
*/
void	rotateBoth(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b);
	setPositions(*a);
	setPositions(*b);
}

void	reverseRotateBoth(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b);
	setPositions(*a);
	setPositions(*b);
}

/*
 * Conclude the rotation of the stacks 
*/
void	finishRotation(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->half == 1)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->half == 1)
				rb(stack);
			else
				rrb(stack);
		}	
	}
}

/*
 * Move the node from 'b' to 'a'
 * with the metadata available in the node
 * 1)Make the target nodes emerge
 * 2)push in A
*/
void	moveOne(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = returnCheapest(*b);
	if (cheapest->half == 1 && cheapest->target->half == 1)
		rotateBoth(a, b, cheapest);
	else if ((cheapest->half == 0) && (cheapest->target->half == 0))
		reverseRotateBoth(a, b, cheapest);
	finishRotation(b, cheapest, 'b');
	finishRotation(a, cheapest->target, 'a');
	pa(a, b);
}

/*
 * ~Push all nodes in B 
 * ~For every configuration choose the "cheapest_node"
 * ~Push everything back in A in order
*/
void	pushSwap(t_stack **a, t_stack **b)
{
	t_stack	*smallest_node;
	int		len_a;

	len_a = stackLen(*a);
	if (len_a == 5)
		sortFive(a, b);
	else
		push2B(a, b, len_a);
	sortThree(a);
	while (*b)
	{
		setStuff(*a, *b);
		moveOne(a, b);
	}
	setPositions(*a);
	smallest_node = smallestNode(*a);
	if (smallest_node->half == 1)
		while (*a != smallest_node)
			ra(a);
	else
		while (*a != smallest_node)
			rra(a);
}

