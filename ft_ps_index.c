/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:35:32 by lsohler           #+#    #+#             */
/*   Updated: 2023/01/16 14:14:40 by lsohler          ###   ########.fr       */
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

void	ft_ps_index(int *tab, t_list **ps_list, size_t len)
{
	size_t	y;
	size_t	i;
	int		*sorted_tab;

	y = 0;
	i = 0;
	sorted_tab = ft_ps_sort_tab(tab, len);
	while (y < len)
	{
		if (sorted_tab[y] == (*ps_list)->content)
		{
			(*ps_list)->index = y + 1;
			i++;
			if (i == len)
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
