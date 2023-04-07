/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:36:19 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/07 15:39:15 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrr(t_list **pile_a, t_list **pile_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(pile_a, pile_b);
	}
}

void	do_rr(t_list **pile_a, t_list **pile_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr(pile_a, pile_b);
	}	
}

void	rotate_a(t_list **pile_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			ft_ra(pile_a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			ft_rra(pile_a);
			(*cost_a)++;
		}
	}
}

void	rotate_b(t_list **pile_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			ft_ra(pile_b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			ft_rra(pile_b);
			(*cost_b)++;
		}
	}
}

void	do_move(t_list **pile_a, t_list **pile_b, t_data *data)
{
	int	cost_a;
	int	cost_b;

	cost_a = data->cost_a;
	cost_b = data->cost_b;
	printf("cost_a= %i cost_b= %i\n", cost_a, cost_b);
	if (cost_a < 0 && cost_b < 0)
		do_rrr(pile_a, pile_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rr(pile_a, pile_b, &cost_a, &cost_b);
	rotate_a(pile_a, &cost_a);
	rotate_b(pile_b, &cost_b);
	ft_pa(pile_a, pile_b, data);
}