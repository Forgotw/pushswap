/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:57:42 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/14 12:44:46 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_operation(char *line, t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	if (ft_strcmp(line, "pa\n") == 1)
		checker_pa(pile_a, pile_b, ps_data);
	else if (ft_strcmp(line, "pb\n") != 0)
		checker_pb(pile_a, pile_b, ps_data);
	else if (ft_strcmp(line, "ra\n") != 0)
		ft_rotate(pile_a);
	else if (ft_strcmp(line, "rb\n") != 0)
		ft_rotate(pile_b);
	else if (ft_strcmp(line, "rra\n") != 0)
		ft_r_rotate(pile_a);
	else if (ft_strcmp(line, "rrb\n") != 0)
		ft_r_rotate(pile_b);
	else if (ft_strcmp(line, "rr\n") != 0)
		checker_rr(pile_a, pile_b);
	else if (ft_strcmp(line, "rrr\n") != 0)
		checker_rrr(pile_a, pile_b);
	else if (ft_strcmp(line, "sa\n") != 0)
		ft_swap(pile_a);
	else if (ft_strcmp(line, "sb\n") != 0)
		ft_swap(pile_b);
	else if (ft_strcmp(line, "ss\n") != 0)
		checker_ss(pile_a, pile_b);
	else
		return (0);
	return (1);
}

int	check_line(t_list **pile_a, t_list **pile_b, t_data *ps_data)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (do_operation(line, pile_a, pile_b, ps_data) == 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		line = NULL;
		line = get_next_line(0);
	}
	return (1);
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
	check_line(&pile_a, &pile_b, ps_data);
	if (ps_sorted_check(pile_a, ps_data) == 1)
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	ps_free(&pile_a, ps_data);
	free(pile_b);
	free(ps_data);
	free_tab_array(array, tab, argc, 0);
}
