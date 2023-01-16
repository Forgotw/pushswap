/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:43:50 by lsohler           #+#    #+#             */
/*   Updated: 2023/01/16 11:19:29 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pos	*ft_ps_find_new(size_t a, size_t b, size_t c, int d)
{
	t_pos	*find;

	find = malloc(sizeof (t_pos *));
	if (!find)
		return (NULL);
	find->index = a;
	find->pos = b;
	find->start = c;
	find->pile = d;
	return (find);
}

t_pos	*ft_ps_find(t_range *range, t_list *pile_top, t_list *pile_bot)
{
	size_t	top_i;
	size_t	bot_i;
	t_pos	*find;

	top_i = 1;
	bot_i = range->len;
	printf("RANGE MAIN x: %i y: %i len: %i pile: %i\n", (int)range->x, (int)range->y, (int)range->len, (int)range->pile);
	while (top_i <= ((range->len / 2) +1))
	{
		if (pile_top->index >= range->x && pile_top->index <= range->y)
		{
			find = ft_ps_find_new(pile_top->index, top_i, 0, range->pile);
			printf("RANGE AFTER x: %i y: %i len: %i pile: %i\n", (int)range->x, (int)range->y, (int)range->len, (int)range->pile);
			return (find);
		}
		else if (pile_bot->index >= range->x && pile_bot->index <= range->y)
		{
			find = ft_ps_find_new(pile_bot->index, bot_i, 1, range->pile);
			return (find);
		}
		pile_top = pile_top->next;
		pile_bot = pile_bot->prev;
		top_i++;
		bot_i--;
	}
	return (NULL);
}
//reste a gerer NULL find
void	rotate_to_find(t_list **pile, t_pos *find, t_range *range)
{
	size_t	i;

	if (!find)
	{
		printf("number not found\n");
		return ;
	}
	printf("FIND ROTATE index: %i pos: %i start: %i\n", (int)find->index, (int)find->pos, (int)find->start);
	printf("RANGE ROTATE x: %i y: %i len: %i pile: %i\n", (int)range->x, (int)range->y, (int)range->len, (int)range->pile);
	if (find->start == 0)
	{
		i = 1;
		while (i < find->pos)
		{
			printf("test while rotate, %i\n", range->pile);
			
			if (range->pile == 1)
			{
				printf("abc\n");
				ft_ra(pile);
				printf("test if rotate\n");
			}
			if (range->pile == 2)
			{
				ft_rb(pile);
			}
			i++;
		}
	}
	else if (find->start == 1)
	{
		i = find->pos - 1;
		while (i <= range->len)
		{
			printf("test while r_rotate, %i\n", range->pile);
			if (range->pile == 1)
				ft_rra(pile);
			else if (range->pile == 2)
			{
				ft_rrb(pile);
			}
			i++;
		}
	}
}