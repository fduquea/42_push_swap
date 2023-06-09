/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:02:47 by fduque-a          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/19 19:39:24 by fduque-a         ###   ########.fr       */
=======
/*   Updated: 2023/06/20 12:32:50 by fduque-a         ###   ########.fr       */
>>>>>>> 802dd0fa82fd71e264b11d4d4395f5f751b9b06c
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap_bonus.h"

static int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 == *str2 && *str1)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

static void	error(t_stack **a, t_stack **b)
{
	stack_free(a);
	stack_free(b);
	write(2, "Error\n", 6);
	exit(1);
}

static int	get_command(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(a, b, true);
	else if (!ft_strcmp(command, "pb\n"))
		pb(b, a, true);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, true);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, true);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, true);
	else
		return (0);
	return (1);
}

void	get_lines(t_stack **a, t_stack **b)
{
	char	*next_line;
	int		i;

	next_line = get_next_line(0);
	while (next_line)
	{
		i = get_command(a, b, next_line);
		if (i == 0)
		{
			free(next_line);
			error(a, b);
		}
		free(next_line);
		next_line = get_next_line(0);
	}
	free(next_line);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		argv = ft_split(argv[1], 32);
	if (argv == NULL)
		error(&a, &b);
	create_stack(&a, argv + 1, argc);
	len = stack_len(a);
	get_lines(&a, &b);
	if (is_sorted(a) && stack_len(a) == len)
		write(1, "Ok\n", 3);
	else
		write(1, "KO\n", 3);
	stack_free(&a);
	stack_free(&b);
}
