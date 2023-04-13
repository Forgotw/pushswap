/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:14:01 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/10 18:08:42 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (pile_b->pos > (data->lenb / 2))
			pile_b->cost_b = (int)((data->lenb - pile_b->pos) * -1);
		pile_b->cost_a = (int)pile_b->target_pos;
		if (pile_b->target_pos > (data->lena / 2))
			pile_b->cost_a = (int)((data->lena - pile_b->target_pos) * -1);
		//*pile_bb = pile_b;
		//printf("testteeeeeeeeest: pile_bpos: %i cost_b: %i tmp_pos: %i cost_tmp: %i\n", (*pile_bb)->pos, (*pile_bb)->cost_b, pile_b->pos, pile_b->cost_b);
		pile_b = pile_b->next;
		//printf("testteeeeeeeeest: pile_bpos: %i cost_b: %i\n", (int)(*pile_bb)->pos, (int)(*pile_bb)->cost_b);
	}
	//*pile_bb = (*pile_bb)->next;
}

/*
void	assign_cost(t_list **pile_b, t_data *data)
{
	size_t	i;
	t_list	*tmp;

	tmp = *pile_b;
	i = 0;
	while (i++ < data->lenb)
	{
		//printf("test: pile_b pos: %i\n", (int)(*pile_b)->pos);
		(*pile_b)->cost_b = tmp->pos;
		tmp->cost_b = tmp->pos;
		//printf("testteeeeeeeeest: pile_bpos: %i cost_b: %i tmp_pos: %i cost_tmp: %i\n", (*pile_b)->pos, (*pile_b)->cost_b, tmp->pos, tmp->cost_b);
		if ((*pile_b)->pos > (data->lenb / 2))
			(*pile_b)->cost_b = ((data->lenb - (*pile_b)->pos) * -1);
		(*pile_b)->cost_a = (*pile_b)->target_pos;
		if ((*pile_b)->target_pos > (data->lena / 2))
			(*pile_b)->cost_a = ((data->lena - (*pile_b)->target_pos) * -1);
		//printf("testteeeeeeeeest: pile_bpos: %i cost_b: %i tmp_pos: %i cost_tmp: %i\n", (*pile_b)->pos, (*pile_b)->cost_b, tmp->pos, tmp->cost_b);
		//*pile_b = (*pile_b)->next;
		tmp = tmp->next;
	}
	//ft_printflist(NULL, *pile_b, data->lena, data->lenb);
}*/

/*
void	assign_cost(t_list **pile_b, t_data *data)
{
	size_t	i;
	
	i = 0;
	while (i++ < data->lenb)
	{
		//printf("test: pile_b pos: %i\n", (int)(*pile_b)->pos);
		(*pile_b)->cost_b = (int)(*pile_b)->pos;
		//printf("testteeeeeeeeest: pile_bpos: %i cost_b: %i\n", (int)(*pile_b)->pos, (int)(*pile_b)->cost_b);
		if ((*pile_b)->pos > (data->lenb / 2))
			(*pile_b)->cost_b = (int)((data->lenb - (*pile_b)->pos) * -1);
		(*pile_b)->cost_a = (int)(*pile_b)->target_pos;
		if ((*pile_b)->target_pos > (data->lena / 2))
			(*pile_b)->cost_a = (int)((data->lena - (*pile_b)->target_pos) * -1);
		*pile_b = (*pile_b)->next;
	}
}*/


/*void	do_best_move(t_list **pile_a, t_list **pile_b, t_data *data)
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
}*/

void	do_best_move(t_list **pile_a, t_list **pile_b, t_data *data)
{
	t_list	*list;
	int		cheapest;
	int		cheapest_new;
	size_t	i;

	i = 0;
	cheapest = data->len + 1;
	list = *pile_b;
	while (i++ < data->lenb)
	{
		if (list->cost_a <= 0 && list->cost_b <= 0)
		{
			//printf("test\n");
			if (list->cost_a <= list->cost_b)
				cheapest_new = ft_abs(list->cost_a);
			else
				cheapest_new = ft_abs(list->cost_b);
		}
		else if (list->cost_a >= 0 && list->cost_b >= 0)
		{
			//printf("test2\n");
			if (list->cost_a >= list->cost_b)
				cheapest_new = list->cost_a;
			else
				cheapest_new = list->cost_b;
		}
		else
		{
			//printf("test3\n");
			cheapest_new = ft_abs(list->cost_a) + ft_abs(list->cost_b);
		}
		if (cheapest_new < cheapest)
		{
			//printf("test4: %i\n", cheapest);
			cheapest = cheapest_new;
			data->cost_a = list->cost_a;
			data->cost_b = list->cost_b;
		}
		list = list->next;
	}
	//printf("test: pile_b cost_b: %i\n", (int)(*pile_b)->cost_b);
	do_move(pile_a, pile_b, data);
}

void	rotate_to_first(t_list **pile_a, t_data *data)
{
	int		i;
	t_list	*tmp;
	int		first_pos;

	i = 0;
	tmp = *pile_a;
	assign_pos(pile_a, data->lena);
	while (tmp->index != 1)
	{
		tmp = tmp->next;
	}
	first_pos = tmp->pos;
	while ((*pile_a)->index != 1)
	{
		if (first_pos <= data->lena / 2)
			ft_ra(pile_a);
		else
			ft_rra(pile_a);
		i++;
	}
}