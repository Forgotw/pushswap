/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:23:15 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/07 15:54:33 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* POSITIONS */
void	assign_pos(t_list **list, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		(*list)->pos = i;
		*list = (*list)->next;
		i++;
	}
}

void	get_target_smallest(t_list **pile_a, size_t index_b, t_data *data)
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
}

void	get_target_pos(t_list **pile_a, t_list **pile_b, t_data *data)
{
	int	target_pos;
	size_t	i;

	i = 0;
	data->target_pos = 0;
	data->target_index = data->len;
	assign_pos(pile_a, data->lena);
	assign_pos(pile_b, data->lenb);
	while (i++ < data->lenb)
	{
		target_pos = get_target(pile_a, (*pile_b)->index, data);
		printf("TARGETPOOOOOOOOOS = %i\n", data->target_pos);
		(*pile_b)->target_pos = data->target_pos;
		*pile_b = (*pile_b)->next;
	}
}