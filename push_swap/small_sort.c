/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:29:01 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/17 00:06:41 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		set_stuff(*a, *b);
		finish_rotation(a, smallest_node(*a), 'a');
		pb(b, a, false);
	}
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = biggest_node(*a);
	if (biggest == *a)
		ra(a, false);
	else if (biggest == (*a)->next)
		rra(a, false);
	if ((*a)->data > (*a)->next->data)
		sa(a, false);
}
