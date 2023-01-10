/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:45:28 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/01/05 13:07:07 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_list **pile)
{
	size_t	tmpindex;
	int		tmpcontent;

	if (!pile || (*pile)->next == NULL)
		return ;
	tmpindex = (*pile)->index;
	(*pile)->index = (*pile)->next->index;
	(*pile)->next->index = tmpindex;
	tmpcontent = (*pile)->content;
	(*pile)->content = (*pile)->next->content;
	(*pile)->next->content = tmpcontent;
}

void	ft_sa(t_list **pile)
{
	ft_swap(pile);
	write (1, "sa\n", 3);
}

void	ft_sb(t_list **pile)
{
	ft_swap(pile);
	write (1, "sb\n", 3);
}

void	ft_ss(t_list **pile_a, t_list **pile_b)
{
	ft_swap(pile_a);
	ft_swap(pile_b);
	write (1, "ss\n", 3);
}
