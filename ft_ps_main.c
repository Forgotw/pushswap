/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:53:51 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/01/03 16:33:09 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t ft_arraylen(char **array)
{
    size_t  i;

    i = 0;
    while (array[i])
        i++;
    return (i);
}

void    ft_rev_printflist(t_list *pslist)
{
    pslist = ft_ps_lstlast(pslist);
    while (pslist->prev != NULL)
    {
        printf("pslist: %i  index: %i  len: %i\n", pslist->content, (int)pslist->index, (int)pslist->len);
        pslist = pslist->prev;
        if (pslist->prev == NULL)
            printf("pslist: %i  index: %i  len: %i\n", pslist->content, (int)pslist->index, (int)pslist->len);
    }
}

void    ft_printflist(t_list *pslist)
{
    size_t  i;

    i = 0;
    write (1, "T\n", 2);
    while (i <= pslist->len)
    {
        printf("pslist: %i  index: %i  len: %i\n", pslist->content, (int)pslist->index, (int)pslist->len);
        pslist = pslist->next;
        i++;
    }
}

int main(int argc, char **argv)
{
    //char    *array[] = {"123", "5", "54", "67", "3", "23", NULL};
    char    **array;
    int     i;
    t_list  *pslist;
    int     *tab;

    array = ft_ps_arg_split(argc, argv);
    tab = ft_array_to_tab(array);
    if (ft_ps_check_error(array, tab, argc) == 0)
    {
        printf("Error");
        return (0);
    }
    tab = ft_array_to_tab(array);
    pslist = ft_split_to_list(tab, array);
    i = 0;
    while (array[i])
    {
        printf("%s ", array[i]);
        i++;
    }
    printf("\n%i\n", (int)ft_arraylen(array));
    ft_ps_index(tab, pslist);
    write (1, "T2\n", 3);
    ft_printflist(pslist);
    ft_sa(pslist);
    ft_printflist(pslist);
    //ft_rev_printflist(pslist);
}