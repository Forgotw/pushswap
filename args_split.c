/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:22:16 by lsohler@stu       #+#    #+#             */
/*   Updated: 2022/12/07 12:33:31 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_ps_argcheck()
char    **ft_ps_argsplit(int ac, char **av)
{
    char **array;

    if (ac == 2)
        array = ft_split(av[1])
}