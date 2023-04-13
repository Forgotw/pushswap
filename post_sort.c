/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:23:15 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/10 15:37:17 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* POSITIONS */
void	assign_pos(t_list **list, size_t len)
{
	size_t	i;
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

/*void	get_target_smallest(t_list **pile_a, size_t index_b, t_data *data)
{
	size_t	i;

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

size_t	get_target(t_list **pile_a, size_t index_b, t_data *data)
{
	size_t	i;

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
	get_target_smallest(pile_a, index_b, data);
	return (data->target_pos);
}*/

int	get_target(t_list **pile_a, int b_idx, t_data *data)
{
	t_list	*tmp_a;
	size_t	i;

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
}

void	get_target_pos(t_list **pile_a, t_list **pile_b, t_data *data)
{
	int	target_pos;
	t_list	*tmp;
	size_t	i;

	i = 0;
	tmp = *pile_b;
	data->target_pos = 0;
	assign_pos(pile_a, data->lena);
	assign_pos(pile_b, data->lenb);
	while (i++ < data->lenb)
	{
		data->target_index = data->len;
		target_pos = get_target(pile_a, tmp->index, data);
		//printf("TARGETPOOOOOOOOOS = %i\n", target_pos);
		tmp->target_pos = data->target_pos;
		tmp = tmp->next;
	}
}