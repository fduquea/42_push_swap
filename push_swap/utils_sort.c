/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:55:40 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/18 00:43:15 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b, int size)
{
	int		b_len;
	int		i;

	b_len = 0;
	i = 0;
	get_final_index(*a, size);
	while (size > 6 && i < size && b_len < size / 2)
	{
		if ((*a)->final_index <= size / 2)
		{
			pb(b, a, false);
			b_len++;
		}
		else
			ra(a, false);
		i++;
	}
	while (size - b_len > 3)
	{
		pb(b, a, false);
		b_len++;
	}
}

void	get_final_index(t_stack *a, int size)
{
	t_stack	*temp;
	t_stack	*curr_index;
	int		temp_data;

	while (size--)
	{
		temp = a;
		temp_data = INT_MIN;
		curr_index = NULL;
		while (temp)
		{
			if (temp->data == INT_MIN && temp->final_index == 0)
				temp->final_index = 1;
			else if (temp->data > temp_data && temp->final_index == 0)
			{
				temp_data = temp->data;
				curr_index = temp;
				temp = a;
			}
			else
				temp = temp->next;
		}
		if (curr_index)
			curr_index->final_index = size + 1;
	}
}

int	max_value(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_stack	*return_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

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
