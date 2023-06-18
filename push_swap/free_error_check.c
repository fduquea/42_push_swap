/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:28:08 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/18 01:55:38 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_fake_argv(char **argv)
{
	int	i;

	if (!argv || !(*argv))
		return ;
	i = -1;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	stack_free(t_stack **a)
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

int	check_repetion(t_stack *a, int n)
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

int	error_syntax(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '+' && str[0] != '-' && !(str[0] >= '0' && str[0] <= '9'))
		return (1);
	if ((str[0] == '-' && !(str[1] >= '0' && str[1] <= '9'))
		|| (str[0] == '+' && !(str[1] >= '0' && str[1] <= '9')))
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	stack_error(t_stack **a, char **argv, int argc, bool status)
{
	if (argc == 2 && argv[1])
		free_fake_argv(argv);
	stack_free(a);
	if (status == false)
		write(2, "Error\n", 6);
	exit(1);
}
