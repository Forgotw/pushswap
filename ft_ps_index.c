/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:35:32 by lsohler           #+#    #+#             */
/*   Updated: 2023/01/06 13:24:46 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_ps_sort_tab(int *tab, size_t len)
{
	size_t	i;
	int		tmp;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
		{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				i = 0;
		}
		else
			i++;
	}
	i = 0;
	return (tab);
}

void	ft_ps_index(int *tab, t_list **ps_list)
{
	size_t	y;
	int		*sorted_tab;

	y = 0;
	sorted_tab = ft_ps_sort_tab(tab, (*ps_list)->len);
	while (y < (*ps_list)->len)
	{
		if (sorted_tab[y] == (*ps_list)->content)
		{
			(*ps_list)->index = y + 1;
			if ((*ps_list)->pos == (*ps_list)->len)
			{
				break ;
			}
			else
				*ps_list = (*ps_list)->next;
			y = 0;
		}
		else
			y++;
	}
	*ps_list = (*ps_list)->next;
}
