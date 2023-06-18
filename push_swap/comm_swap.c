/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:07:17 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/17 00:07:35 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The swap function itself
*/
void	swap(t_stack **stack)
{
	int	len;

	len = stack_len(*stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

/*
** Swap the first 2 elements
** at the top of stack a
*/
void	sa(t_stack **stack, bool status)
{
	swap(stack);
	if (status == false)
		write(1, "sa\n", 3);
}

/*
** Swap the first 2 elements
** at the top of stack b
*/
void	sb(t_stack **stack, bool status)
{
	swap(stack);
	if (status == false)
		write(1, "sb\n", 3);
}

/*
** 'sa' and 'sb'  at the same time
*/
void	ss(t_stack **a, t_stack **b, bool status)
{
	swap(a);
	swap(b);
	if (status == false)
		write(1, "ss\n", 3);
}
