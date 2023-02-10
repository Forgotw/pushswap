/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_post_sort2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:29:41 by lsohler           #+#    #+#             */
/*   Updated: 2023/02/10 16:38:40 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ps_find_pos(size_t index, size_t len, t_list *pile_top, t_list *pile_bot)
{
	size_t	top_i;
	size_t	bot_i;

	top_i = 1;
	bot_i = len;
	while (top_i <= ((len / 2) + 1))
	{
		if (pile_top->index == index)
		{
			return (top_i);
		}
		else if (pile_bot->index == index)
		{
			return (bot_i);
		}
		pile_top = pile_top->next;
		pile_bot = pile_bot->prev;
		top_i++;
		bot_i--;
	}
	return (0);
}

void	ps_find_fastest()
{
	
}