/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:53:51 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/01/04 13:50:26 by lsohler          ###   ########.fr       */
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
/*
void	ft_rev_printflist(t_list *pslist)
{
	pslist = ft_ps_lstlast(pslist);
	while (pslist->prev != NULL)
	{
		printf("pslist: %i  index: %i  len: %i\n", pslist->content, (int)pslist->index, (int)pslist->len);
		pslist = pslist->prev;
		if (pslist->prev == NULL)
			printf("pslist: %i  index: %i  len: %i\n", pslist->content, (int)pslist->index, (int)pslist->len);
	}
}
*/
void	ft_printflist(t_list *pslist, t_list *pslist2)
{
	size_t	i;

	i = 0;
	while (i < pslist->len)
	{
		if (pslist)
		{
			printf("pile a: %i  index: %i  len: %i pos: %i       ", pslist->content, (int)pslist->index, (int)pslist->len, (int)pslist->pos);
			pslist = pslist->next;
		}
		if (!pslist)
			printf("pile a vide");
		if (pslist2)
		{
			printf("pile b: %i  index: %i  len: %i pos: %i       \n", pslist2->content, (int)pslist2->index, (int)pslist2->len, (int)pslist2->pos);
			pslist2 = pslist2->next;
		}
		if (!pslist2)
			printf("pile b vide\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**array;
	int		i;
	t_list	*pile_a;
	t_list	*pile_b;
	int		*tab;

	pile_b = NULL;
	array = ft_ps_arg_split(argc, argv);
	tab = ft_array_to_tab(array);
	if (ft_ps_check_error(array, tab, argc) == 0)
	{
		printf("Error");
		return (0);
	}
	tab = ft_array_to_tab(array);
	pile_a = ft_split_to_list(tab, array);
	i = 0;
	while (array[i])
	{
		printf("%s ", array[i]);
		i++;
	}
	printf("\n%i\n", (int)ft_arraylen(array));
	ft_ps_index(tab, pile_a);
	if (pile_b == NULL)
		printf("pile b vide\n");
	ft_printflist(pile_a, pile_b);
	//printf("pile a: %i  index: %i  len: %i       \n", pile_a->content, (int)pile_a->index, (int)pile_a->len);
	printf("pile_a->prev: %i\n", (int)pile_a->prev->content);
	ft_printflist(pile_a, pile_b);
	printf("pile_a->prev: %i\n", (int)pile_a->prev->content);
	//printf("pile a: %i  index: %i  len: %i       \n", pile_a->content, (int)pile_a->index, (int)pile_a->len);
	ft_sa(pile_a);
	ft_printflist(pile_a, pile_b);
	printf("pile_a->prev: %i\n", (int)pile_a->prev->content);
	ft_ra(pile_a);
	ft_printflist(pile_a, pile_b);
	printf("pile_a->prev: %i\n", (int)pile_a->prev->content);
	//ft_rev_printflist(pslist);
}
