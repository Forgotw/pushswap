/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_pre_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:19:36 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/04/14 12:56:36 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_3(t_list **pile_a, t_data *ps_data)
{
	if (ps_sorted_check(*pile_a, ps_data) == 1)
		return ;
	if ((*pile_a)->index == ps_data->len)
		ft_ra(pile_a);
	else if ((*pile_a)->next->index == ps_data->len)
		ft_rra(pile_a);
	if ((*pile_a)->index > (*pile_a)->next->index)
		ft_sa(pile_a);
}

void	ft_pre_sort(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	int	i;

	ps_data->x = 1;
	ps_data->y = (ps_data->len / 2);
	i = 1;
	while (ps_data->lena > 3)
	{
		ps_rotate_to_find(pile_a, ps_data);
		ft_pb(pile_a, pile_b, ps_data);
		if (ps_data->index < (ps_data->x + ((ps_data->y - ps_data->x) / 2)))
			ft_rb(pile_b);
		if (i == ps_data->y)
		{
			ps_data->x = i + 1;
			ps_data->y = i + (ps_data->lena / 2);
			if ((ps_data->y - ps_data->x) < 10)
			{
				ps_data->y = ps_data->x + 10;
				if (ps_data->len - ps_data->y < 10)
					ps_data->y = ps_data->len - 3;
			}
		}
		i++;
	}
}
