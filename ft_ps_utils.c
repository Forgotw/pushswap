/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:31:57 by lsohler           #+#    #+#             */
/*   Updated: 2023/01/03 16:39:53 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *ft_ps_lstnew(int content)
{
	t_list	*elt;

	if (!(elt = (t_list*)malloc(sizeof(*elt))))
		return (NULL);
	elt->content = content;
	elt->next = NULL;
    elt->prev = NULL;
	return (elt);
}

t_list  *ft_ps_lstlast(t_list *lst)
{
    if (lst)
        while (lst->next != NULL)
            lst = lst->next;
    return (lst);
}

t_list  *ft_ps_lstfirst(t_list *lst)
{
    if (lst)
        while (lst->prev != NULL)
            lst = lst->prev;
    return (lst);
}

t_list    *ft_split_to_list(int *tab, char **array)
{
    size_t  i;
    t_list  *pslist;
    t_list  *top;
    size_t  x;

    x = 0;
    while (array[x])
        x++;
    i = 0;
    pslist = ft_ps_lstnew(tab[i]);
    pslist->len = x;
    top = pslist;
    while (++i != x)
    {
        pslist->next = ft_ps_lstnew((int)tab[i]);
        pslist->next->prev = pslist;
        pslist = pslist->next;
        pslist->len = x;
    }
    pslist->next = top;
    pslist->end = 1;
    top->prev = pslist;
    write (1, "T4\n", 3);
    return (top);
}