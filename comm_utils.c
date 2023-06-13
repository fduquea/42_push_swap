/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:34:37 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/12 23:29:05 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*return_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack *a)
{
	int		i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_stack	*last_node(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*smallest(t_stack *stack)
{
	t_stack	*smallest_node;
	long	smallest;
	int		len;

	smallest = LONG_MAX;
	len = stack_len(stack);
	if (stack == NULL || len == 1)
		return (NULL);
	smallest_node = stack;
	while (stack)
	{
		if (stack->data < smallest)
		{
			smallest = stack->data;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack	*biggest(t_stack *stack)
{
	t_stack	*biggest_node;
	long	biggest;
	int		len;

	biggest = LONG_MIN;
	len = stack_len(stack);
	if (stack == NULL || len == 1)
		return (NULL);
	biggest_node = stack;
	while (stack)
	{
		if (stack->data > biggest)
		{
			biggest = stack->data;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}
