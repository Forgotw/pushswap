/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:31:57 by lsohler           #+#    #+#             */
/*   Updated: 2023/01/10 13:33:42 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_ps_lstnew(int content)
{
	t_list	*elt;

	elt = (t_list *)malloc(sizeof(*elt));
	if (!(elt))
		return (NULL);
	elt->content = content;
	elt->next = NULL;
	elt->prev = NULL;
	return (elt);
}

char	**ft_ps_arg_split(int argc, char **argv)
{
	char	**array;

	if (argc > 2)
	{
		array = &argv[1];
	}
	else if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
	}
	else
		return (NULL);
	return (array);
}

t_list	*ft_split_to_list(int *tab, char **array)
{
	size_t	i;
	t_list	*pslist;
	t_list	*top;
	size_t	x;

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
	top->prev = pslist;
	return (top);
}
