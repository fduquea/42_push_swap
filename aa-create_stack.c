/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa-create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:23:41 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/12 22:25:59 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

t_stack	*find_last_node(t_stack *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	add_single_number(t_stack **stack, int num)
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
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	create_stack(t_stack **a, char **args, int argc)
{
	int		i;
	long	n;

	i = 0;
	while (args[i])
	{
		if (error_syntax(args[i]))
			stack_error(a, args, argc);
		n = ft_atol(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			stack_error(a, args, argc);
		if (check_repetition(*a, n))
			stack_error(a, args, argc);
		add_single_number(a, (int)n);
		i++;
	}
	if (argc == 2)
		free_fake_argv(args);
}
