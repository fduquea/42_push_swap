/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a-push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:18:07 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/13 01:07:23 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || !argv[1][0])
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], 32);
	create_stack(&a, argv + 1, argc);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			ft_push_swap(&a, &b);
	}
	// while(a)
	// {
	// 	printf("%i ", (int)a->data);
	// 	a = a->next;
	// }
	// stack_free(&a);
}
