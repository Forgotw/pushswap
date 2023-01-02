/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:31:57 by lsohler           #+#    #+#             */
/*   Updated: 2022/12/12 12:02:57 by lsohler          ###   ########.fr       */
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