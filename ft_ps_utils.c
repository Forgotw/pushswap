/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:31:57 by lsohler           #+#    #+#             */
/*   Updated: 2023/01/19 20:21:20 by lsohler@stu      ###   ########.fr       */
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
	top = pslist;
	while (++i != x)
	{
		pslist->next = ft_ps_lstnew((int)tab[i]);
		pslist->next->prev = pslist;
		pslist = pslist->next;
	}
	pslist->next = top;
	top->prev = pslist;
	return (top);
}

int ps_sorted_check(t_list *pile_a, t_data *ps_data)
{
	size_t	i;

	i = 1;
	while (pile_a->index == pile_a->next->index + 1)
	{
		pile_a = pile_a->next;
		i++;
	}
	if (i == ps_data->lena)
		return (1);
	return (0);
}
