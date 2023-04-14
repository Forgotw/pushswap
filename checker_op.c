/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:41:55 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/14 11:42:00 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_pa(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	if (ps_data->lenb != 0)
	{
		ft_push(pile_b, pile_a, ps_data->lenb, ps_data->lena);
		ps_data->lena += 1;
		ps_data->lenb -= 1;
	}
}

void	checker_pb(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	if (ps_data->lena != 0)
	{
		ft_push(pile_a, pile_b, ps_data->lena, ps_data->lenb);
		ps_data->lenb += 1;
		ps_data->lena -= 1;
	}
}

void	checker_rrr(t_list **pile_a, t_list **pile_b)
{
	ft_r_rotate(pile_a);
	ft_r_rotate(pile_b);
}

void	checker_rr(t_list **pile_a, t_list **pile_b)
{
	ft_rotate(pile_a);
	ft_rotate(pile_b);
}

void	checker_ss(t_list **pile_a, t_list **pile_b)
{
	ft_swap(pile_a);
	ft_swap(pile_b);
}
