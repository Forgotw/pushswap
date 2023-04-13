/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:49:07 by lsohler           #+#    #+#             */
/*   Updated: 2023/04/10 18:17:05 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_free(t_list **pile_a, t_data *ps_data)
{
	t_list	*tmp;
	size_t	i;

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

void free_split(char **array, int argc)
{
	size_t	i;

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