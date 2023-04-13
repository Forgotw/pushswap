/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:29:43 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/13 17:29:53 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	pushswap(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	size_t	i;

	i = 0;
	ft_pre_sort(pile_a, pile_b, ps_data);
	ps_sort_3(pile_a, ps_data);
	while (ps_data->lenb > 0)
	{
		get_target_pos(pile_a, pile_b, ps_data);
		assign_cost(pile_b, ps_data);
		do_best_move(pile_a, pile_b, ps_data);
		i++;
	}
	rotate_to_first(pile_a, ps_data);
}

int	main(int argc, char **argv)
{
	char	**array;
	t_list	*pile_a;
	t_list	*pile_b;
	int		*tab;
	t_data	*ps_data;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	pile_b = NULL;
	array = ft_ps_arg_split(argc, argv);
	tab = ft_array_to_tab(array);
	if (ft_ps_check_error(array, tab, argc) == 0)
		return (free_tab_array(array, tab, argc, 1));
	pile_a = ft_split_to_list(tab, array);
	ft_ps_index(tab, &pile_a, ft_arraylen(array));
	ps_data = ps_new_data(ft_arraylen(array));
	if (ps_sorted_check(pile_a, ps_data) == 0)
		pushswap(&pile_a, &pile_b, ps_data);
	ps_free(&pile_a, ps_data);
	free(pile_b);
	free(ps_data);
	free_tab_array(array, tab, argc, 0);
}
