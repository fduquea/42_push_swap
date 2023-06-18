/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:07:27 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/16 23:56:27 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The rotate function itself
*/
void	rotate(t_stack **stack)
{
	t_stack	*temp;
	int		len;

	len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	temp = last_node(*stack);
	temp->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next->prev = temp;
	temp->next->next = NULL;
}

/*
** Shift up all elements
**   of stack a by 1
*/
void	ra(t_stack **stack, bool status)
{
	rotate(stack);
	if (status == false)
		write(1, "ra\n", 3);
}

/*
** Shift up all elements
**   of stack b by 1
*/
void	rb(t_stack **stack, bool status)
{
	rotate(stack);
	if (status == false)
		write(1, "rb\n", 3);
}

/*
** 'ra' and 'rb' at the same time
*/
void	rr(t_stack **a, t_stack **b, bool status)
{
	rotate(a);
	rotate(b);
	if (status == false)
		write(1, "rr\n", 3);
}
