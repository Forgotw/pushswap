/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:47:28 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/01/10 13:20:58 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
}*/
//extrait une pile de s(pile_s->next->prev = pile_s->prev, pile_s->prev->next = pile_s->next)
t_list	*ft_pa_extract(t_list **pile_s, size_t len_s)
{
	t_list	*push;

	push = *pile_s;
	if (len_s > 1)
	{
		(*pile_s)->prev->next = (*pile_s)->next;
		(*pile_s)->next->prev = (*pile_s)->prev;
		*pile_s = (*pile_s)->next;
	}
	if (len_s == 1)
		*pile_s = NULL;
	push->next = NULL;
	push->prev = NULL;
	return (push);
}
void	ft_pa_insert(t_list *insert, t_list **pile_d, size_t len_d)
{
	if (len_d > 1)
	{
		(*pile_d)->prev->next = insert;
		insert->prev = (*pile_d)->prev;
		(*pile_d)->prev = insert;
		insert->next = *pile_d;
	}
	else if (len_d == 1)
	{
		(*pile_d)->next = insert;
		(*pile_d)->prev = insert;
		insert->next = *pile_d;
		insert->prev = *pile_d;
	}
	*pile_d = insert;
}

size_t	ft_push(t_list **pile_s, t_list **pile_d, size_t len_s, size_t len_d)
{
	t_list *push;

	if (*pile_s == NULL)
		return (0);
	else
	{
		push = ft_pa_extract(pile_s, len_s);
		ft_pa_insert(push, pile_d, len_d);
		return (1);
	}
}

size_t	ft_pa(t_list **pile_a, t_list **pile_b, size_t len_a, size_t len_b)
{
	write (1, "pa\n", 3);
	return (ft_push(pile_b, pile_a, len_b, len_a));
}

size_t	ft_pb(t_list **pile_a, t_list **pile_b, size_t len_a, size_t len_b)
{
	write (1, "pb\n", 3);
	return (ft_push(pile_a, pile_b, len_a, len_b));
}