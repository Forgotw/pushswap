/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:14:01 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/07 15:47:36 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	assign_cost(t_list **pile_bb, t_data *data)
{
	size_t	i;
	t_list	*pile_b;
	
	i = 0;
	pile_b = *pile_bb;
	while (i++ < data->lenb)
	{
		//printf("test: pile_b pos: %i\n", (int)(*pile_bb)->pos);
		pile_b->cost_b = (int)pile_b->pos;
		printf("testteeeeeeeeest: pile_bpos: %i cost_b: %i\n", (int)(*pile_bb)->pos, (int)(*pile_bb)->cost_b);
		if (pile_b->pos > (data->lenb / 2))
			pile_b->cost_b = (int)((data->lenb - pile_b->pos) * -1);
		pile_b->cost_a = (int)pile_b->target_pos;
		if (pile_b->target_pos > (data->lena / 2))
			pile_b->cost_a = (int)((data->lena - pile_b->target_pos) * -1);
		pile_b = pile_b->next;
	}
	*pile_bb = pile_b;
}*/

void	assign_cost(t_list **pile_b, t_data *data)
{
	size_t	i;
	
	i = 0;
	while (i++ < data->lenb)
	{
		//printf("test: pile_b pos: %i\n", (int)(*pile_b)->pos);
		(*pile_b)->cost_b = (int)(*pile_b)->pos;
		printf("testteeeeeeeeest: pile_bpos: %i cost_b: %i\n", (int)(*pile_b)->pos, (int)(*pile_b)->cost_b);
		if ((*pile_b)->pos > (data->lenb / 2))
			(*pile_b)->cost_b = (int)((data->lenb - (*pile_b)->pos) * -1);
		(*pile_b)->cost_a = (int)(*pile_b)->target_pos;
		if ((*pile_b)->target_pos > (data->lena / 2))
			(*pile_b)->cost_a = (int)((data->lena - (*pile_b)->target_pos) * -1);
		*pile_b = (*pile_b)->next;
	}
}


void	do_best_move(t_list **pile_a, t_list **pile_b, t_data *data)
{
	t_list	*list;
	int		cheapest;
	size_t	i;

	i = 0;
	cheapest = data->len + 1;
	list = *pile_b;
	while (i++ < data->lenb)
	{
		//printf("test: pile_b cost_b: %i\n", (int)(*pile_b)->cost_b);
		if (ft_abs(list->cost_a) + ft_abs(list->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(list->cost_b) + ft_abs(list->cost_a);
			data->cost_a = list->cost_a;
			data->cost_b = list->cost_b;
		}
		list = list->next;
	}
	//printf("test: pile_b cost_b: %i\n", (int)(*pile_b)->cost_b);
	do_move(pile_a, pile_b, data);
}