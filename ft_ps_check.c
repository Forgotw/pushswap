/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:37:48 by lsohler           #+#    #+#             */
/*   Updated: 2023/01/02 13:43:27 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char    **ft_ps_arg_split(int argc, char **argv)
{
    char    **array;

    if (argc > 2)
    {
        array = &argv[1];
    }
    else if (argc == 2)
    {
        array = ft_split(argv[1], ' ');
    }
    else
        return (NULL);
    return (array);
}

t_list    *ft_split_to_list(int *tab, char **array)
{
    size_t  i;
    t_list  *pslist;
    t_list  *pslist0;
    size_t  x;

    x = 0;
    while (array[x])
        x++;
    i = 0;
    pslist = ft_ps_lstnew(tab[i]);
    pslist->len = x;
    pslist0 = pslist;
    while (++i != x)
    {
        pslist->next = ft_ps_lstnew((int)tab[i]);
        pslist->next->prev = pslist;
        pslist = pslist->next;
        pslist->len = x;
    }
    return (pslist0);
}

int *ft_array_to_tab(char **array)
{
    int *tab;
    int i;
    int y;

    i = 0;
    y = 0;
    while (array[i])
        i++;
    tab = malloc(sizeof(int) * i);
    while (y != i)
    {
        tab[y] = ft_atoi(array[y]);
        y++;
    }
    return (tab);
}

int ft_ps_check_int(char **array, int *tab)
{
    int i;

    i = 0;
    while (array[i])
    {
        if (ft_strcmp(array[i], ft_itoa(tab[i])) == 0)
            return (0);
        i++;
    }
    return (1);
}

int ft_ps_check_double(int *tab, int arraylen)
{
    int i;
    int y;

    i = 0;
    y = 1;
    while (i != arraylen)
    {
        while (y != arraylen)
        {
            if (tab[i] == tab[y])
                return (0);
            y++;
        }
        i++;
        y = i + 1;
    }
    return (1);
}

int ft_ps_check_digit(char **array)
{
    int i;
    int y;

    i = 0;
    y = 0;

    if (array == NULL)
        return (0);
    while (array[i] != NULL)
    {
        if (array[i][y] == '-')
            y++;
        while (array[i][y] != '\0')
            {
                if (ft_isdigit(array[i][y]) == 1)
                    y++;
                else
                    return (0); 
            }
        y = 0;
        i++;
    }
    return (1);
}

int ft_ps_check_error(char **array, int *tab, int argc)
{
    size_t  i;

    i = 0;
    while (array[i])
        i++;
    if (ft_ps_check_digit(array) == 0 
    || ft_ps_check_double(tab, i) == 0 
    || ft_ps_check_int(array, tab) == 0
    ||  argc < 2)
    {
        return (0);
    }
    else
        return (1);

}
