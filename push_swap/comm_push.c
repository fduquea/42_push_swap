/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:09:28 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/16 23:54:53 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The push function itself
*/
void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node;

	if (*src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dest;
		node->next->prev = node;
		*dest = node;
	}
}

/*
** Take the first element at the top
** of b and put it at the top of a
*/
void	pa(t_stack **a, t_stack **b, bool status)
{
	push(a, b);
	if (status == false)
		write(1, "pa\n", 3);
}

/*
** Take the first element at the top
** of a and put it at the top of b
*/
void	pb(t_stack **b, t_stack **a, bool status)
{
	push(b, a);
	if (status == false)
		write(1, "pb\n", 3);
}
