/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_pre_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:19:36 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/01/24 16:27:41 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_3(t_list **pile_a, t_data *ps_data)
{
	//printf("ps_data i: %i p: %i l: %i la: %i lb: %i x: %i y: %i pile: %c\n", (int)ps_data->index, (int)ps_data->pos, (int)ps_data->len, (int)ps_data->lena, (int)ps_data->lenb, (int)ps_data->x, (int)ps_data->y, ps_data->pile);
	if (ps_sorted_check(*pile_a, ps_data) == 1)
		return ;
	//printf("ps_data i: %i p: %i l: %i la: %i lb: %i x: %i y: %i pile: %c\n", (int)ps_data->index, (int)ps_data->pos, (int)ps_data->len, (int)ps_data->lena, (int)ps_data->lenb, (int)ps_data->x, (int)ps_data->y, ps_data->pile);
	if ((*pile_a)->index == ps_data->len)
		ft_ra(pile_a);
	else if ((*pile_a)->next->index == ps_data->len)
		ft_rra(pile_a);
	if ((*pile_a)->index > (*pile_a)->next->index)
		ft_sa(pile_a);
}

void	ft_pre_sort(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	//size_t	range_x;
	//size_t	range_y;
	size_t	i;
	//tant que la len de pile_a >= 3
	//divise la len en 3, find tout les nombre du groupe 1 push, find tous les nombre du groupe 2 push puis reverse rotate
	//range_x = 1;
	//range_y = (ps_data->len / 3);
	ps_data->x = 1;
	ps_data->y = (ps_data->len / 5);
	i = 1;
	while (ps_data->lena > 3)
	{
		ps_rotate_to_find(pile_a, ps_data);
		ft_pb(pile_a, pile_b, ps_data);
		if (ps_data->index < (ps_data->x + ((ps_data->y - ps_data->x) / 2)))
		{
			ft_rb(pile_b);
			//printf("ooooooooooooooooooTEST RB\n");
		}
		if (i == ps_data->y)
		{
			ps_data->x = i + 1;
			ps_data->y = i + (ps_data->lena / 4);
			//printf("           ps_data->x: %i ps_data->y: %i\n", (int)ps_data->x, (int)ps_data->y);
			if ((ps_data->y - ps_data->x) < 3)
			{
				ps_data->y = ps_data->x + 2;
				if (ps_data->len - ps_data->y < 3)
					ps_data->y = ps_data->len - 3;
			}
		}
		i++;
	}
}

void	ps_rotate_to_find_b(t_list **pile, t_data *ps_data)
{
	size_t	i;

	if (ps_find(ps_data, *pile, (*pile)->prev) == 0)
		return ;
	if (ps_data->pos <= (ps_data->len / 2))
	{
		i = 1;
		while (i < ps_data->pos)
		{
			ft_rb(pile);
			i++;
		}
	}
	else if (ps_data->pos > (ps_data->len / 2))
	{
		i = ps_data->pos;
		while (i <= ps_data->len)
		{
			ft_rrb(pile);
			i++;
		}
	}
}


int	ps_find_b(t_data *ps_data, t_list *pile_top, t_list *pile_bot)
{
	size_t	top_i;
	size_t	bot_i;

	top_i = 1;
	bot_i = ps_data->lenb;
	while (top_i <= ((ps_data->lenb / 2) +1))
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

void	ps_post_sort(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	size_t	i;

	i = 0;
	ps_sort_3(pile_a, ps_data);
	while (*pile_b)
	{
		//ps_data->x = ps_data->len - 3 - i;
		ps_data->x = (*pile_a)->index - 1;
		ps_data->y = ps_data->x;
		//ps_rotate_to_find_b(pile_b, ps_data);
		//ft_pa(pile_a, pile_b, ps_data);
		ps_find_b(ps_data, *pile_b, (*pile_b)->prev);
		//printf("test ps_post_sort\n");
		ps_sort_to_find(pile_a, pile_b, ps_data);
		i++;
	}
}

void	ps_sort_to_find(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	//si la pos de next_index = (index - 1) est a plus de 5, n = si (pos <= lenb / 2) n = pos) sinon n = lenb - pos
	//pour n pusha de façon decroissante j'usqu'a que next soit au sommet de la b
	//rotate j'usqu'a revenir a index puis push
	//j'usqu'a ce que le new next_index ne soit pas dans pile_a rotate
	//
	//
	//
	//tant que je ne suis pas a index - 1, pa si plus petit , si plus grand rra j'usqu'a plus petit puis pa
	size_t	i;

	if (ps_data->pos <= (ps_data->lenb / 2))
	{
		i = 1;
		while (i < ps_data->pos)
		{
			//printf("test boucle if top\n");
			if ((*pile_b)->index < (*pile_a)->index)
				ft_pa(pile_a, pile_b, ps_data);
			else if ((*pile_b)->index > (*pile_a)->index)
			{
				while ((*pile_b)->index > (*pile_a)->index)
					ft_rra(pile_a);
				ft_pa(pile_a, pile_b, ps_data);
			}
			i++;
		}
	}
	else if (ps_data->pos > (ps_data->lenb / 2))
	{
		i = ps_data->pos;
		while (i <= ps_data->lenb)
		{
			//printf("test boucle if bot\n");
			ft_rrb(pile_b);
			if ((*pile_b)->index < (*pile_a)->index)
				ft_pa(pile_a, pile_b, ps_data);
			else if ((*pile_b)->index > (*pile_a)->index)
			{
				while ((*pile_b)->index > (*pile_a)->index)
					ft_rra(pile_a);
				ft_pa(pile_a, pile_b, ps_data);
			}
			i++;
		}
	}
	ft_pa(pile_a, pile_b, ps_data);
	while ((*pile_a)->index == (*pile_a)->prev->index + 1)
		ft_rra(pile_a);
	//printf("test ps_sort_to_find\n");
}