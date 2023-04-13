/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:31:57 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/13 15:22:29 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_arraylen(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

t_list	*ft_ps_lstnew(int content)
{
	t_list	*elt;

	elt = (t_list *)malloc(sizeof(*elt));
	if (!(elt))
		return (NULL);
	elt->content = content;
	elt->cost_a = 0;
	elt->cost_b = 0;
	elt->target_pos = 0;
	elt->pos = 0;
	elt->next = NULL;
	elt->prev = NULL;
	elt->index = 0;
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
	int		i;
	t_list	*pslist;
	t_list	*top;
	int		x;

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

int	ps_sorted_check(t_list *pile_a, t_data *ps_data)
{
	int	i;

	i = 1;
	if (pile_a->index != 1)
		return (0);
	while (pile_a->index + 1 == pile_a->next->index)
	{
		pile_a = pile_a->next;
		i++;
	}
	if (i == ps_data->lena)
		return (1);
	return (0);
}
