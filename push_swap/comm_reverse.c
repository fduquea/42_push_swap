/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:09:09 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/16 23:55:39 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The reverse rotate function itself
*/
void	reverse(t_stack **stack)
{
	t_stack	*node;
	int		len;

	len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	node = last_node(*stack);
	node->prev->next = NULL;
	node->next = *stack;
	node->prev = NULL;
	*stack = node;
	node->next->prev = node;
}

/*
** Shift down all elements
**   of stack a by 1
*/
void	rra(t_stack **stack, bool status)
{
	reverse(stack);
	if (status == false)
		write(1, "rra\n", 4);
}

/*
** Shift down all elements
**   of stack b by 1
*/
void	rrb(t_stack **stack, bool status)
{
	reverse(stack);
	if (status == false)
		write(1, "rrb\n", 4);
}

/*
** 'ra' and 'rb' at the same time
*/
void	rrr(t_stack **a, t_stack **b, bool status)
{
	reverse(a);
	reverse(b);
	if (status == false)
		write(1, "rrr\n", 4);
}
