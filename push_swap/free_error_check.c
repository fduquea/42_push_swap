/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa-create_stack_errors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:28:08 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/16 21:26:22 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeFakeArgv(char **args)
{
	int	i;

	if (args == NULL || *args == NULL)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args - 1);
}

void	stackFree(t_stack **a)
{
	t_stack	*temp;
	t_stack	*current;

	if (a == NULL)
		return ;
	current = *a;
	while (current && current->next)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(current);
	*a = NULL;
}

int	checkRepetition(t_stack *a, int n)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->data == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	errorSyntax(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '+' && str[0] != '-' && !(str[0] >= '0' && str[0] <= '9'))
		return (1);
	if ((str[0] == '-' && !(str[1] >= '0' && str[1] <= '9')) || (str[0] == '+' && !(str[1] >= '0' && str[1] <= '9')))
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	stackError(t_stack **a, char **args, int argc)
{
	if (argc == 2 && args[1])
		freeFakeArgv(args);
	stackFree(a);
	write(2, "Error\n", 6);
	exit(1);
}
