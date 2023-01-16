/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_pre_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:19:36 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/01/12 13:59:59 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pre_sort()
{
	//tant que la len de pile_a >= 3
	//divise la len en 3, find tout les nombre du groupe 1 push, find tous les nombre du groupe 2 push puis reverse rotate

}

t_range *ft_ps_new_range(size_t x, size_t y, size_t len, int pile)
{
	t_range *range;

	range = malloc(sizeof (t_range *));
	if (!range)
		return (NULL);
	range->len = len;
	range->pile = pile;
	range->x = x;
	range->y = y;
	return (range);
}