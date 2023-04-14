/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:14:01 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/14 12:59:22 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_cost(t_list **pile_bb, t_data *data)
{
	int		i;
	t_list	*pile_b;

	i = 0;
	pile_b = *pile_bb;
	while (i++ < data->lenb)
	{
		pile_b->cost_b = (int)pile_b->pos;
		if (pile_b->pos > (data->lenb / 2))
			pile_b->cost_b = (int)((data->lenb - pile_b->pos) * -1);
		pile_b->cost_a = (int)pile_b->target_pos;
		if (pile_b->target_pos > (data->lena / 2))
			pile_b->cost_a = (int)((data->lena - pile_b->target_pos) * -1);
		pile_b = pile_b->next;
	}
}

int	calcul_cheapest(t_list *list)
{
	int	cheapest_new;

	if (list->cost_a <= 0 && list->cost_b <= 0)
	{
		if (list->cost_a <= list->cost_b)
			cheapest_new = ft_abs(list->cost_a);
		else
			cheapest_new = ft_abs(list->cost_b);
	}
	else if (list->cost_a >= 0 && list->cost_b >= 0)
	{
		if (list->cost_a >= list->cost_b)
			cheapest_new = list->cost_a;
		else
			cheapest_new = list->cost_b;
	}
	else
	{
		cheapest_new = ft_abs(list->cost_a) + ft_abs(list->cost_b);
	}
	return (cheapest_new);
}

void	do_best_move(t_list **pile_a, t_list **pile_b, t_data *data)
{
	t_list	*list;
	int		cheapest;
	int		cheapest_new;
	int		i;

	i = 0;
	cheapest = data->len + 1;
	list = *pile_b;
	while (i++ < data->lenb)
	{
		cheapest_new = calcul_cheapest(list);
		if (cheapest_new < cheapest)
		{
			cheapest = cheapest_new;
			data->cost_a = list->cost_a;
			data->cost_b = list->cost_b;
		}
		list = list->next;
	}
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

void	pushswap(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	size_t	i;

	i = 0;
	ft_pre_sort(pile_a, pile_b, ps_data);
	ps_sort_3(pile_a, ps_data);
	while (ps_data->lenb > 0)
	{
		get_target_pos(pile_a, pile_b, ps_data);
		assign_cost(pile_b, ps_data);
		do_best_move(pile_a, pile_b, ps_data);
		i++;
	}
	rotate_to_first(pile_a, ps_data);
}
