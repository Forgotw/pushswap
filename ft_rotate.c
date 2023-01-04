/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:05:01 by lsohler           #+#    #+#             */
/*   Updated: 2023/01/04 14:58:01 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_rotate(t_list *pslist)
{
	//t_list *tmp;
	t_list	*bot;
	t_list	*top;
	size_t	i;
	t_list	*pslist2;

	if (!pslist || pslist->next == NULL)
		return ;
	/*tmp = pslist;
	tmp->prev = pslist->prev->prev;
	pslist->prev->pos = 1;
	pslist = pslist->prev;
	pslist->prev = tmp;
	tmp->pos = tmp->prev->pos + 1;
	tmp->next = pslist;
	*/
	bot = pslist;
	top = pslist->next;
	top->pos = 1;
	//bot->pos = pslist->prev->pos + 1;
	top->next = pslist->next->next;
	top->prev = bot;
	bot->prev = pslist->prev->prev;
	bot->next = top;
	pslist->prev = bot;
	pslist = top;
	i = 0;
	pslist2 = NULL;
	while (i < pslist->len)
	{
		if (pslist)
		{
			printf("RApile a: %i  index: %i  len: %i pos: %i       ", pslist->content, (int)pslist->index, (int)pslist->len, (int)pslist->pos);
			pslist = pslist->next;
		}
		if (!pslist)
			printf("pile a vide");
		if (pslist2)
		{
			printf("RApile b: %i  index: %i  len: %i pos: %i       \n", pslist2->content, (int)pslist2->index, (int)pslist2->len, (int)pslist2->pos);
			pslist2 = pslist2->next;
		}
		if (!pslist2)
			printf("pile b vide\n");
		i++;
	}
}

void	ft_ra(t_list *pile)
{
	ft_rotate(pile);
	write (1, "ra\n", 3);
}

void	ft_rb(t_list *pile)
{
	ft_rotate(pile);
	write (1, "rb\n", 3);
}

void	ft_rr(t_list *pile_a, t_list *pile_b)
{
	ft_rotate(pile_a);
	ft_rotate(pile_b);
	write (1, "rr\n", 3);
}
