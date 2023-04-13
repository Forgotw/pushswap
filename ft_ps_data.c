/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:31:24 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/13 15:19:49 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ps_new_data(size_t lenght)
{
	t_data	*ps_data;

	ps_data = malloc(sizeof (t_data));
	if (!ps_data)
		return (NULL);
	ps_data->index = 0;
	ps_data->pos = 0;
	ps_data->len = lenght;
	ps_data->lena = lenght;
	ps_data->lenb = 0;
	ps_data->x = 0;
	ps_data->y = 0;
	return (ps_data);
}

void	ps_data_range(t_data *ps_data, size_t range_x, size_t range_y)
{
	ps_data->x = range_x;
	ps_data->y = range_y;
}

void	ps_find_data(t_data *ps_data, size_t i, size_t p)
{
	ps_data->index = i;
	ps_data->pos = p;
}

int	ps_find(t_data *ps_data, t_list *pile_top, t_list *pile_bot)
{
	int	top_i;
	int	bot_i;

	top_i = 1;
	bot_i = ps_data->len;
	while (top_i <= ((ps_data->len / 2) + 1))
	{
		if (pile_top->index >= ps_data->x && pile_top->index <= ps_data->y)
		{
			ps_find_data(ps_data, pile_top->index, top_i);
			return (1);
		}
		else if (pile_bot->index >= ps_data->x && pile_bot->index <= ps_data->y)
		{
			ps_find_data(ps_data, pile_bot->index, bot_i);
			return (1);
		}
		pile_top = pile_top->next;
		pile_bot = pile_bot->prev;
		top_i++;
		bot_i--;
	}
	return (0);
}

void	ps_rotate_to_find(t_list **pile, t_data *ps_data)
{
	int	i;

	if (ps_find(ps_data, *pile, (*pile)->prev) == 0)
		return ;
	if (ps_data->pos <= (ps_data->len / 2))
	{
		i = 1;
		while (i < ps_data->pos)
		{
			ft_ra(pile);
			i++;
		}
	}
	else if (ps_data->pos > (ps_data->len / 2))
	{
		i = ps_data->pos;
		while (i <= ps_data->len)
		{
			ft_rra(pile);
			i++;
		}
	}
}
