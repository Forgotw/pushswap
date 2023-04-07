/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:53:51 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/04/07 15:48:54 by lsohler          ###   ########.fr       */
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

void	ft_printflist(t_list *pslist, t_list *pslist2, size_t lena, size_t lenb)
{
	size_t	i;
	
	i = 0;
	while (i < (lena + lenb))
	{
		if (pslist && i < lena)
		{
			printf("pile a: %i  index: %i pos: %i target_pos: %i cost_a: %i cost_b: %i         ", pslist->content, (int)pslist->index, (int)pslist->pos, (int)pslist->target_pos, (int)pslist->cost_a, (int)pslist->cost_a);
			pslist = pslist->next;
		}
		if (i >= lena)
			printf("pile a vide");
		if (pslist2 && i < lenb)
		{
			printf("pile b: %i  index: %i pos: %i target_pos: %i cost_a: %i cost_b: %i         \n", pslist2->content, (int)pslist2->index, (int)pslist2->pos, (int)pslist2->target_pos, (int)pslist2->cost_a, (int)pslist2->cost_a);
			pslist2 = pslist2->next;
		}
		if (i >= lenb)
			printf("pile b vide\n");
		i++;
	}
}

void	pushswap(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
		ft_pre_sort(pile_a, pile_b ,ps_data);
		ps_sort_3(pile_a, ps_data);
		while (ps_data->lenb > 95)
		{
			get_target_pos(pile_a, pile_b, ps_data);
			assign_cost(pile_b, ps_data);
			ft_printflist(*pile_a, *pile_b, ps_data->lena, ps_data->lenb);
			printf("TEEEEEEEEEEEEEEEEST: pile_bpos: %i cost_b: %i\n", (int)(*pile_b)->pos, (int)(*pile_b)->cost_b);
			do_best_move(pile_a, pile_b, ps_data);
		}
}

int	main(int argc, char **argv)
{
	char	**array;
	t_list	*pile_a;
	t_list	*pile_b;
	int		*tab;
	t_data	*ps_data;
	t_list *tmp_a;
	t_list *tmp_b;

	pile_b = NULL;
	array = ft_ps_arg_split(argc, argv);
	tab = ft_array_to_tab(array);
	if (ft_ps_check_error(array, tab, argc) == 0)
	{
		free(tab);
		free_split(array, argc);
		write(1, "Error\n", 6);
		return (0);
	}
	pile_a = ft_split_to_list(tab, array);
	ft_ps_index(tab, &pile_a, ft_arraylen(array));
	ps_data = ps_new_data(ft_arraylen(array));
	if (ps_sorted_check(pile_a, ps_data) == 0)
		pushswap(&pile_a, &pile_b, ps_data);
	/*
	ps_free(&pile_a, ps_data);
	free(pile_b);
	if (argc == 2 && array)
		free_split(array, argc);
	free(tab);*/
}
