/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:53:51 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/01/10 13:36:54 by lsohler          ###   ########.fr       */
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
void	ft_printflist(t_list *pslist, t_list *pslist2, size_t lena, size_t lenb)
{
	size_t	i;

	i = 0;
	while (i < (lena + lenb))
	{
		if (pslist && i < lena)
		{
			printf("pile a: %i  index: %i  len: %i       ", pslist->content, (int)pslist->index, (int)pslist->len);
			pslist = pslist->next;
		}
		if (i >= lena)
			printf("pile a vide");
		if (pslist2 && i < lenb)
		{
			printf("pile b: %i  index: %i  len: %i       \n", pslist2->content, (int)pslist2->index, (int)pslist2->len);
			pslist2 = pslist2->next;
		}
		if (i >= lenb)
			printf("pile b vide\n");
		i++;
	}
}

void	ft_printab(t_list *pslist, t_list *pslist2, size_t lena, size_t lenb)
{
	size_t	i;

	i = 0;
	while (i < lena)
	{
		printf("pile a: %i  index: %i  len: %i\n", pslist->content, (int)pslist->index, (int)pslist->len);
		pslist = pslist->next;
		i++;
	}
	i = 0;
	printf("\n\n\n");
	while (i < lenb)
	{
			printf("pile b: %i  index: %i  len: %i       \n", pslist2->content, (int)pslist2->index, (int)pslist2->len);
			pslist2 = pslist2->next;
			i++;
	}
}

int	main(int argc, char **argv)
{
	char	**array;
	//int		i;
	t_list	*pile_a;
	t_list	*pile_b;
	int		*tab;
	char	buf[20];
	size_t	lena;
	size_t	lenb;

	pile_b = NULL;
	(void)pile_b;
	array = ft_ps_arg_split(argc, argv);
	tab = ft_array_to_tab(array);
	if (ft_ps_check_error(array, tab, argc) == 0)
	{
		printf("Error");
		return (0);
	}
	tab = ft_array_to_tab(array);
	pile_a = ft_split_to_list(tab, array);
	ft_ps_index(tab, &pile_a);
	lena = pile_a->len;
	lenb = 0;
	while (ft_strcmp(buf, "exit") == 0)
	{
		scanf("%s", buf);
		if (ft_strcmp("print", buf) == 1)
		{
			ft_printflist(pile_a, pile_b, lena, lenb) ;
		}
		if (ft_strcmp("printab", buf) == 1)
		{
			ft_printab(pile_a, pile_b, lena, lenb) ;
		}
		if (ft_strcmp("sa", buf) == 1)
		{
			ft_sa(&pile_a);
		}
		if (ft_strcmp("ra", buf) == 1)
		{
			ft_ra(&pile_a);
		}
		if (ft_strcmp("rra", buf) == 1)
		{
			ft_rra(&pile_a);
		}
		if (ft_strcmp("rrr", buf) == 1)
		{
			ft_rrr(&pile_a, &pile_b);
		}
		if (ft_strcmp("pa", buf) == 1)
		{
			if (ft_pa(&pile_a, &pile_b, lena, lenb) == 1)
			{
				lena += 1;
				lenb -= 1;
			}
		}
		if (ft_strcmp("pb", buf) == 1)
		{
			if (ft_pb(&pile_a, &pile_b, lena, lenb) == 1)
			{
				lena -= 1;
				lenb += 1;
			}
		}
	}
}
