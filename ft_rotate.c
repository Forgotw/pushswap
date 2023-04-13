/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:05:01 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/13 15:23:53 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_rotate(t_list **pslist)
{
	if (!pslist || (*pslist)->next == NULL)
		return ;
	*pslist = (*pslist)->next;
}

void	ft_ra(t_list **pile)
{
	ft_rotate(pile);
	write (1, "ra\n", 3);
}

void	ft_rb(t_list **pile)
{
	ft_rotate(pile);
	write (1, "rb\n", 3);
}

void	ft_rr(t_list **pile_a, t_list **pile_b)
{
	ft_rotate(pile_a);
	ft_rotate(pile_b);
	write (1, "rr\n", 3);
}
