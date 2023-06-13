/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:07:17 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/12 23:49:37 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The swap function itself
*/

void	swap(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	t_stack *first = *stack;
	t_stack *second = (*stack)->next;

	first->next = second->next;
	first->prev = second;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;

	*stack = second;
}

/*
** Swap the first 2 elements
** at the top of stack a
*/

void	sa(t_stack **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

/*
** Swap the first 2 elements
** at the top of stack b
*/

void	sb(t_stack **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

/*
** 'sa' and 'sb'  at the same time
*/

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

