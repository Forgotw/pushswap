/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:35:32 by lsohler           #+#    #+#             */
/*   Updated: 2023/01/03 16:40:28 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *ft_ps_sort_tab(int *tab, t_list *ps_list)
{
    size_t  i;
    int     tmp;

    i = 0;
    while (i < ps_list->len - 1)
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

void    ft_ps_index(int *tab, t_list *ps_list)
{
    size_t  y;
    int     *sorted_tab;

    y = 0;
    sorted_tab = ft_ps_sort_tab(tab, ps_list);
    while (y < ps_list->len)
    {
        write (1, "T7\n", 3);
        if (sorted_tab[y] == ps_list->content)
        {
            ps_list->index = y + 1;
            ps_list = ps_list->next;
            y = 0;
            if (ps_list->end == 1)
                break;
        }
        else
            y++;
    }
}