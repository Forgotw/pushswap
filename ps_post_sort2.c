/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_post_sort2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:29:41 by lsohler           #+#    #+#             */
/*   Updated: 2023/02/27 14:12:00 by lsohler          ###   ########.fr       */
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

void	ps_check_for_insert(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	if ((*pile_b)->index == (*pile_a)->index - 1 || (*pile_b)->prev->index == (*pile_a)->index - 1)
	{
		while ((*pile_b)->index == (*pile_a)->index - 1)
			ft_pa(pile_a, pile_b, ps_data);
		while ((*pile_b)->prev->index == (*pile_a)->index - 1)
		{
			ft_rrb(pile_b);
			ft_pa(pile_a, pile_b, ps_data);
		}
		ps_data->pos = 0;
	}
	else if ((*pile_b)->next->index == (*pile_a)->index - 1)
	{
		while ((*pile_b)->next->index == (*pile_a)->index - 1)
		{
			ft_sb(pile_b);
			ft_pa(pile_a, pile_b, ps_data);
		}
		ps_data->pos = 0;
	}
}

void	ps_sort_to_index(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	//printf("test\n");
	while ((*pile_b)->index != ps_data->index && (*pile_b)->prev->index != ps_data->index)
	{
		//printf("test3\n");
		if (ps_data->pos > ps_data->lenb / 2)
			ft_rrb(pile_b);
		if ((*pile_a)->prev->index == ps_data->len)
			sort_if_bot_clear(pile_a, pile_b, ps_data);
		else if ((*pile_a)->prev->index != ps_data->len)
			sort_if_bot_unclear(pile_a, pile_b, ps_data);
		if ((*pile_b) == NULL)
			break ;
	}
	//ft_pa(pile_a, pile_b, ps_data);
	while ((*pile_a)->index - (*pile_a)->prev->index == 1)
	{
		//ps_check_for_insert(pile_a, pile_b, ps_data);
		ft_rra(pile_a);
	}
}

void ps_post_sort_main2(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	size_t	i;

	i = 0;
	ps_sort_3(pile_a, ps_data);
	while (*pile_b != NULL && i < 11000)
	{
		i++;
		if ((*pile_b)->index == (*pile_a)->index - 1 || (*pile_b)->prev->index == (*pile_a)->index - 1)
		{
			while ((*pile_b)->index == (*pile_a)->index - 1)
				ft_pa(pile_a, pile_b, ps_data);
			while ((*pile_b)->prev->index == (*pile_a)->index - 1)
			{
				ft_rrb(pile_b);
				ft_pa(pile_a, pile_b, ps_data);
			}
		}
		else if ((*pile_b)->next->index == (*pile_a)->index - 1)
		{
			while ((*pile_b)->next->index == (*pile_a)->index - 1)
			{
				ft_sb(pile_b);
				ft_pa(pile_a, pile_b, ps_data);
			}
		}
		/*if ((*pile_b)->index == (*pile_a)->index - 1)
			ft_pa(pile_a, pile_b, ps_data);
		else if ((*pile_b)->prev->index == (*pile_a)->index - 1)
		{
			ft_rrb(pile_b);
			ft_pa(pile_a, pile_b, ps_data);
		}*/
		else
		{
			ps_data->x = (*pile_a)->index - 1;
			ps_data->y = ps_data->x;
			while (ps_find_b(ps_data, *pile_b, (*pile_b)->prev) == 0 && ps_data->x <= 1)
			{
				//printf("test2\n");
				ps_data->x -= 1;
				ps_data->y = ps_data->x;
				//printf("ps_data i: %i p: %i l: %i la: %i lb: %i x: %i y: %i pile: %c\n", (int)ps_data->index, (int)ps_data->pos, (int)ps_data->len, (int)ps_data->lena, (int)ps_data->lenb, (int)ps_data->x, (int)ps_data->y, ps_data->pile);
				i++;
			}
			//ps_find_b(ps_data, *pile_b, (*pile_b)->prev);
			ps_sort_to_index(pile_a, pile_b, ps_data);
		}
	}
	//while ((*pile_a)->index != 1)
	//	ft_rra(pile_a);
}