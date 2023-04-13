/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:23:15 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/13 15:29:21 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_pos(t_list **list, int len)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *list;
	while (i < len)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	get_target_smallest(t_list **pile_a, t_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->lena)
	{
		if ((*pile_a)->index < data->target_index)
		{
			data->target_index = (*pile_a)->index;
			data->target_pos = (*pile_a)->pos;
		}
		(*pile_a) = (*pile_a)->next;
	}
}

int	get_target(t_list **pile_a, int index_b, t_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->lena)
	{
		if ((*pile_a)->index > index_b && (*pile_a)->index < data->target_index)
		{
			data->target_index = (*pile_a)->index;
			data->target_pos = (*pile_a)->pos;
		}
		(*pile_a) = (*pile_a)->next;
	}
	if (data->target_index != data->len)
		return (data->target_pos);
	get_target_smallest(pile_a, data);
	return (data->target_pos);
}
/*
int	get_target(t_list **pile_a, int b_idx, t_data *data)
{
	t_list	*tmp_a;
	int		i;

	tmp_a = *pile_a;
	i = 0;
	while (i++ < data->lena)
	{
		if (tmp_a->index > b_idx && tmp_a->index < data->target_index)
		{
			data->target_index = tmp_a->index;
			data->target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	i = 0;
	if (data->target_index != data->len)
		return (data->target_pos);
	tmp_a = *pile_a;
	while (i++ < data->lena)
	{
		if (tmp_a->index < data->target_index)
		{
			data->target_index = tmp_a->index;
			data->target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (data->target_pos);
}*/

void	get_target_pos(t_list **pile_a, t_list **pile_b, t_data *data)
{
	int		target_pos;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *pile_b;
	data->target_pos = 0;
	assign_pos(pile_a, data->lena);
	assign_pos(pile_b, data->lenb);
	while (i++ < data->lenb)
	{
		data->target_index = data->len;
		target_pos = get_target(pile_a, tmp->index, data);
		tmp->target_pos = data->target_pos;
		tmp = tmp->next;
	}
}
