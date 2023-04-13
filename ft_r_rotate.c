/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:38:22 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/04/13 15:24:17 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_r_rotate(t_list **pslist)
{
	if (!pslist || (*pslist)->next == NULL)
		return ;
	*pslist = (*pslist)->prev;
}

void	ft_rra(t_list **pile)
{
	ft_r_rotate(pile);
	write (1, "rra\n", 4);
}

void	ft_rrb(t_list **pile)
{
	ft_r_rotate(pile);
	write (1, "rrb\n", 4);
}

void	ft_rrr(t_list **pile_a, t_list **pile_b)
{
	ft_r_rotate(pile_a);
	ft_r_rotate(pile_b);
	write (1, "rrr\n", 4);
}
