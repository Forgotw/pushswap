/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_post_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:39:20 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/01/24 12:16:02 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	si index bot != len:
//		si plus petit que top: tant que bot index > index pa: rra puis push
//		si plus grand que top: tant que bot index < index pa: ra puis push ()
void sort_if_bot_unclear(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	//	si pile_a->prev != ps_data->len:
	//			tant que pile_a->prev->index > pile_b->index et que pile_a->prev->index < ps_data->len: rra
	//			ensuite pa
	if ((*pile_b)->index == ps_data->index)
		return ;
	//printf("test4\n");
	if ((*pile_b)->index < (*pile_a)->index)
	{
		while ((*pile_a)->prev->index > (*pile_b)->index && (*pile_a)->prev->index < ps_data->len)
			ft_rra(pile_a);
		ft_pa(pile_a, pile_b, ps_data);
	}
	else if ((*pile_b)->index > (*pile_a)->index)
	{
		while ((*pile_b)->index > (*pile_a)->index)
			ft_ra(pile_a);
		ft_pa(pile_a, pile_b, ps_data);
	}
}

void sort_if_bot_clear(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	//	si pile_a->prev = ps_data->len:
	//		si pile_b->index < pile_a->index pa, 
	//		si pile_b->index > pile_a->index: 
	//						si sa croissant pa sa(opti), sinon ra j'usqu'a pile_b->index < pile_a->index pa
	if ((*pile_b)->index == ps_data->index)
		return ;
	if ((*pile_b)->index < (*pile_a)->index)
		ft_pa(pile_a, pile_b, ps_data);
	else if ((*pile_b)->index > (*pile_a)->index)
	{
		if ((*pile_b)->index < (*pile_a)->next->index)
		{
			ft_pa(pile_a, pile_b, ps_data);
			ft_sa(pile_a);
		}
		else if ((*pile_b)->index > (*pile_a)->next->index)
		{
			while ((*pile_a)->index < (*pile_b)->index)
				ft_ra(pile_a);
			ft_pa(pile_a, pile_b, ps_data);
			}
	}
}

void	ps_post_sort_to_find(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	//tant qu'on est pas sur to find, 
	//	si index bot = len:
	//		si plus petit que top pa, 
	//		si plus grand que top : 
	//						si sa croissant pa sa(opti), sinon ra j'usqu'a top index > index pa puis push 
	//	si index bot != len:
	//		si plus petit que top: tant que bot index > index pa: rra puis push
	//		si plus grand que top: tant que bot index < index pa: ra puis push ()
	//tant qu'on est pas sur tofind + 1 rra puis push
	//tant que index bot = index top - 1, ra
	//          repeter operation avec to find top - 1
	while ((*pile_b)->index != ps_data->index && (*pile_b)->prev->index != ps_data->index)
	{
		if (ps_data->pos > ps_data->lenb / 2)
			ft_rrb(pile_b);
		//printf("ps_data i: %i p: %i l: %i la: %i lb: %i x: %i y: %i pile: %c\n", (int)ps_data->index, (int)ps_data->pos, (int)ps_data->len, (int)ps_data->lena, (int)ps_data->lenb, (int)ps_data->x, (int)ps_data->y, ps_data->pile);
		//printf("test1\n");
		if ((*pile_a)->prev->index == ps_data->len)
		{
			//printf("test2\n");
			sort_if_bot_clear(pile_a, pile_b, ps_data);
		}
		else if ((*pile_a)->prev->index != ps_data->len)
		{
			//printf("test3\n");
			sort_if_bot_unclear(pile_a, pile_b, ps_data);
		}
		if ((*pile_b) == NULL)
			break ;
	}
	while ((*pile_a)->index != ps_data->index + 1)
		ft_ra(pile_a);
	if (ps_data->pos > ps_data->lenb / 2 && *pile_b)
		ft_rrb(pile_b);
	ft_pa(pile_a, pile_b, ps_data);
	while ((*pile_a)->prev->index == (*pile_a)->index - 1)
		ft_rra(pile_a);
}
	// quand on est sur pile_b->index = ps_data->index
	// tant que pile_a->index != ps_data->index + 1;
	// puis rra tant que pile_a->index == pile_a->prev->index - 1
	// relancer en cherchant pile_a->index - 1
void ps_post_sort_main(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	size_t	i;

	i = 0;
	ps_sort_3(pile_a, ps_data);
	while (*pile_b != NULL)
	{
		if ((*pile_b)->index == (*pile_a)->index - 1)
			ft_pa(pile_a, pile_b, ps_data);
		else
		{
			ps_data->x = (*pile_a)->index - 1;
			ps_data->y = ps_data->x;
			while (ps_find_b(ps_data, *pile_b, (*pile_b)->prev) == 0)
			{
				ps_data->x -= 1;
				ps_data->y = ps_data->x;
				//printf("ps_data i: %i p: %i l: %i la: %i lb: %i x: %i y: %i pile: %c\n", (int)ps_data->index, (int)ps_data->pos, (int)ps_data->len, (int)ps_data->lena, (int)ps_data->lenb, (int)ps_data->x, (int)ps_data->y, ps_data->pile);
				i++;
			}
			//ps_find_b(ps_data, *pile_b, (*pile_b)->prev);
			ps_post_sort_to_find(pile_a, pile_b, ps_data);
		}
	}
	while ((*pile_a)->index != 1)
		ft_rra(pile_a);
}
	//tant qu'on est pas sur ps_data->index
	//si ps_data->pos > ps_data->len / 2 rrb
	//	si pile_a->prev = ps_data->len:
	//		si pile_b->index < pile_a->index pa, 
	//		si pile_b->index > pile_a->index: 
	//						si sa croissant pa sa(opti), sinon ra j'usqu'a pile_b->index < pile_a->index pa
	//	si pile_a->prev != ps_data->len:
	//			tant que pile_a->prev->index > pile_b->index et que pile_a->prev->index < ps_data->len: ra
	//			ensuite pa
	// quand on est sur pile_b->index = ps_data->index
	// tant que pile_a->index != ps_data->index + 1;
	// puis rra tant que pile_a->index == pile_a->prev->index - 1
	// relancer en cherchant pile_a->index - 1
	// si ps_data->pos > ps_data->len / 2
	//	rrb
	//	
	//
	//
