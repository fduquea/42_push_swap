/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:55:40 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/16 22:27:46 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push2B(t_stack **a, t_stack **b, int size)
{
	int		pushed;
	int		i;

	pushed = 0;
	i = 0;
	getFinalIndex(*a, size);
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->final_index <= size / 2)
		{
			pb(b, a);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(b, a);
		pushed++;
	}
}

void	getFinalIndex(t_stack *a, int size)
{
	t_stack	*temp;
	t_stack	*max_address;
	int		max_n;

	while (size--)
	{
		temp = a;
		max_n = INT_MIN;
		max_address = NULL;
		while (temp)
		{
			if (temp->data == INT_MIN && temp->final_index == 0)
				temp->final_index = 1;
			else if (temp->data > max_n && temp->final_index == 0)
			{
				max_n = temp->data;
				max_address = temp;
				temp = a;
			}
			else
				temp = temp->next;
		}
		if (max_address)
			max_address->final_index = size + 1;
	}
}

int	maxValue(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_stack	*returnCheapest(t_stack *stack)
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
