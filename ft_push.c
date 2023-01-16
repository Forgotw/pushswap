/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:47:28 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/01/16 14:06:38 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_pa(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	/*printf("ps_data pa i: %i p: %i l: %i la: %i lb: %i x: %i y: %i pile: %c\n", (int)(*ps_data)->index, (int)(*ps_data)->pos, (int)(*ps_data)->len, (int)(*ps_data)->lena, (int)(*ps_data)->lenb, (int)(*ps_data)->x, (int)(*ps_data)->y, (*ps_data)->pile);
	write (1, "pa\n", 3);
	if (ft_push(pile_b, pile_a, (*ps_data)->lenb, (*ps_data)->lena) == 1)
	{
		(*ps_data)->lena += 1;
		(*ps_data)->lenb -= 1;
	}*/
	printf("ps_data i: %i p: %i l: %i la: %i lb: %i x: %i y: %i pile: %c\n", (int)ps_data->index, (int)ps_data->pos, (int)ps_data->len, (int)ps_data->lena, (int)ps_data->lenb, (int)ps_data->x, (int)ps_data->y, ps_data->pile);
	write (1, "pa\n", 3);
	if (ps_data->lenb != 0)
	{
		ft_push(pile_b, pile_a, ps_data->lenb, ps_data->lena);
		printf("test pb\n");
		ps_data->lena += 1;
		ps_data->lenb -= 1;
	}
}

void	ft_pb(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	printf("ps_data i: %i p: %i l: %i la: %i lb: %i x: %i y: %i pile: %c\n", (int)ps_data->index, (int)ps_data->pos, (int)ps_data->len, (int)ps_data->lena, (int)ps_data->lenb, (int)ps_data->x, (int)ps_data->y, ps_data->pile);
	write (1, "pb\n", 3);
	if (ps_data->lena != 0)
	{
		ft_push(pile_a, pile_b, ps_data->lena, ps_data->lenb);
		printf("test pb\n");
		ps_data->lenb += 1;
		ps_data->lena -= 1;
	}
}