/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:23:41 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/18 01:49:12 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_number(t_stack **stack, int num)
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
		last_node = findlast_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	create_stack(t_stack **a, char **argv, int argc, bool status)
{
	int		i;
	long	n;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			stack_error(a, argv, argc, status);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			stack_error(a, argv, argc, status);
		if (check_repetion(*a, n))
			stack_error(a, argv, argc, status);
		add_number(a, (int)n);
		i++;
	}
	if (argc == 2 && argv[1])
	{
		free_fake_argv(argv);
		argv = NULL;
	}
}

int	is_sorted(t_stack *a)
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
