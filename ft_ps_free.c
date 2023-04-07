/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:49:07 by lsohler           #+#    #+#             */
/*   Updated: 2023/03/25 18:33:26 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_free(t_list **pile_a, t_data *ps_data)
{
	t_list	*tmp;
	
	//printf("%i\n%i\n", (int)(*pile_a)->index, (int)ps_data->lena);
	while ((*pile_a)->index <= ps_data->lena)
	//while (*pile_a && pile_a)
	{
		//printf("%i\n%i\n", (int)(*pile_a)->index, (int)ps_data->lena);
		tmp = (*pile_a)->next;
		free (*pile_a);
		*pile_a = tmp;
	}
	free(ps_data);
	ps_data = NULL;
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