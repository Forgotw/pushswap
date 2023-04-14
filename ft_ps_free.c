/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:49:07 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/14 12:47:14 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free(t_list **pile_a, t_data *ps_data)
{
	t_list	*tmp;
	int		i;

	if (!pile_a || !*pile_a)
		return ;
	i = 0;
	while (i++ < ps_data->lena)
	{
		tmp = (*pile_a)->next;
		free(*pile_a);
		*pile_a = tmp;
	}
	*pile_a = NULL;
}

void	free_split(char **array, int argc)
{
	int	i;

	i = 0;
	if (argc > 2)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	if (array)
		free(array);
}

int	free_tab_array(char **array, int *tab, int argc, int error)
{
	if (error == 1)
		write(2, "Error\n", 6);
	free_split(array, argc);
	free(tab);
	return (0);
}
