/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:05:01 by lsohler           #+#    #+#             */
/*   Updated: 2023/01/06 13:27:33 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_rotate(t_list **pslist)
{
	//t_list *tmp;
	//t_list	*bot;
	//t_list	*top;
	if (!pslist || (*pslist)->next == NULL)
		return ;
	*pslist = (*pslist)->next;
	/*tmp = pslist;
	tmp->prev = pslist->prev->prev;
	pslist->prev->pos = 1;
	pslist = pslist->prev;
	pslist->prev = tmp;
	tmp->pos = tmp->prev->pos + 1;
	tmp->next = pslist;
	*/
	/*
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
	*/
}

void	ft_ra(t_list **pile)
{
	ft_rotate(pile);
	write (1, "ra\n", 3);
}

void	ft_rb(t_list **pile)
{
	ft_rotate(pile);
	write (1, "rb\n", 3);
}

void	ft_rr(t_list **pile_a, t_list **pile_b)
{
	ft_rotate(pile_a);
	ft_rotate(pile_b);
	write (1, "rr\n", 3);
}
