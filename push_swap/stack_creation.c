/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:23:41 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/16 22:17:23 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addNumber(t_stack **stack, int num)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->data = num;
	node->final_index = 0;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = findLastNode(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	createStack(t_stack **a, char **args, int argc)
{
	int		i;
	long	n;

	i = 0;
	while (args[i])
	{
		if (errorSyntax(args[i]))
			stackError(a, args, argc);
		n = ft_atol(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			stackError(a, args, argc);
		if (checkRepetition(*a, n))
			stackError(a, args, argc);
		addNumber(a, (int)n);
		i++;
	}
	if (argc == 2 && args[1])
		freeFakeArgv(args);
}

int	isSorted(t_stack *a)
{
	if (a == NULL)
		return (0);
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}