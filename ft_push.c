/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:47:28 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/01/07 16:59:22 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_list **pile_s, t_list **pile_d)
{
	t_list	*push;

	if (*pile_s == NULL)
		return;
	push = *pile_s;
	(*pile_s)->prev->next = (*pile_s)->next;
	(*pile_s)->next->prev = (*pile_s)->prev;
	*pile_s = (*pile_s)->next;
	if ((*pile_s)->index == (*pile_s)->next->index)
		*pile_s = NULL;
	push->next = *pile_d;
	if (*pile_d != NULL)
	{
		push->prev = (*pile_d)->prev;
		(*pile_d)->prev = push;
		if ((*pile_d)-> next == NULL)
		{
			(*pile_d)->next = push;
			(*pile_d)->prev = push;
		}
		else
		{
			push->prev = (*pile_d)->prev;
			(*pile_d)->prev = push;
		}
	}
	else
		push->prev = NULL;
	*pile_d = push;
}

void	ft_pa(t_list **pile_a, t_list **pile_b)
{
	ft_push(pile_b, pile_a);
	write (1, "pa\n", 3);
}

void	ft_pb(t_list **pile_a, t_list **pile_b)
{
	ft_push(pile_a, pile_b);
	write (1, "pb\n", 3);
}