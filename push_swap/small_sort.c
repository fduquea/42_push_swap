/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:29:01 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/16 22:27:43 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortFive(t_stack **a, t_stack **b)
{
	while (stackLen(*a) > 3)
	{
		setStuff(*a, *b);
		finishRotation(a, smallestNode(*a), 'a');
		pb(b, a);
	}
}

void	sortThree(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = biggestNode(*a);
	if (biggest_node == *a)
		ra(a);
	else if (biggest_node == (*a)->next)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
