/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_pre_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:19:36 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/01/16 15:30:10 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pre_sort(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	size_t	range_x;
	size_t	range_y;
	size_t	i;
	//tant que la len de pile_a >= 3
	//divise la len en 3, find tout les nombre du groupe 1 push, find tous les nombre du groupe 2 push puis reverse rotate
	range_x = 1;
	range_y = (ps_data->len / 3);
	ps_data->x = 1;
	ps_data->y = (ps_data->len / 3);
	i = 1;
	while (ps_data->lena > 3)
	{
		ps_rotate_to_find(pile_a, ps_data);
		ft_pb(pile_a, pile_b, ps_data);
		if (i == ps_data->y)
		{
			ps_data->x = i + 1;
			ps_data->y = i + (ps_data->lena / 3);
			printf("           ps_data->x: %i ps_data->y: %i\n", (int)ps_data->x, (int)ps_data->y);
		}
		i++;
	}
}