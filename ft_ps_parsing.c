/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:43:50 by lsohler           #+#    #+#             */
/*   Updated: 2023/01/10 15:46:29 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pos	*ft_ps_find(t_range *range, t_list *pile_top, t_list *pile_bot)
{
	size_t	top_i;
	size_t	bot_i;
	t_pos	*find;

	top_i = 1;
	bot_i = range->len;
	while (top_i <= (range->len / 2))
	{
		if (pile_top->index >= range->x && pile_top->index <= range->y)
		{
			find->index = pile_top->index;
			find->pos = top_i;
			find->start = 0;
			return (find);
		}
		else if (pile_bot->index >= range->x && pile_bot->index <= range->y)
		{
			find->index = pile_bot->index;
			find->pos = bot_i;
			find->start = 1;
			return (find);
		}
		pile_top = pile_top->next;
		pile_bot = pile_bot->prev;
		top_i++;
		bot_i--;
	}
	return (NULL);
}

t_pos	ft_ps_pos()
void	ft_ps_find_top(t_range *range, t_list *pile_top, t_pos **find)
{
	size_t	i;

	i = 1;
	while (i <= (range->len / 2))
	{
		if (pile_top->index >= range->x && pile_top->index <= range->y)
		{
			(*find)->index = pile_top->index;
			(*find)->pos = i;
			(*find)->start = 0;
		}
		i++;
		pile_top = pile_top->next;
	}
}