/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:45:28 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/04/14 11:28:02 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **pile)
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
