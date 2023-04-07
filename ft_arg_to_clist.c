/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_to_clist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:53:51 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/03/25 17:46:04 by lsohler          ###   ########.fr       */
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

size_t ft_arraylen(char **array)
{
    size_t  i;

    i = 0;
    while (array[i])
        i++;
    return (i);
}

t_list    *ft_split_to_list(int *tab, char **array)
{
    size_t  i;
    t_list  *pslist;
    t_list  *pslist0;
    
    i = 0;
    pslist = ft_ps_lstnew(atoi(array[0]));
    pslist0 = pslist;
    while (array[++i])
    {
        pslist->next = ft_ps_lstnew(atoi(array[i]));
        pslist->next->prev = pslist;
        pslist = pslist->next;
    }
    return (pslist0);
}

void    ft_rev_printflist(t_list *pslist)
{
    pslist = ft_ps_lstlast(pslist);
    while (pslist->prev != NULL)
    {
        printf("pslist: %i\n", pslist->content);
        pslist = pslist->prev;
        if (pslist->prev == NULL)
            printf("pslist: %i\n", pslist->content);
    }
}

void    ft_printflist(t_list *pslist)
{
    pslist = ft_ps_lstfirst(pslist);
    while (pslist->next != NULL)
    {
        printf("pslist: %i\n", pslist->content);
        pslist = pslist->next;
        if (pslist->next == NULL)
            printf("pslist: %i\n", pslist->content);
    }
}