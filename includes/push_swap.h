/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:13 by lsohler@stu       #+#    #+#             */
/*   Updated: 2022/12/05 16:02:40 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef	struct	s_list
{
	int 			content;
	struct s_list	*next;
    struct s_list   *prev;
}				t_list;

#include <stdlib.h>
#include <stdio.h>

#endif