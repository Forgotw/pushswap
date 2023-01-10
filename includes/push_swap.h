/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:13 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/01/07 16:22:38 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef	struct	s_list
{
	size_t			index;
	size_t			pos;
	int 			content;
	size_t			len;
	struct s_list	*next;
    struct s_list   *prev;
	int				end;
}				t_list;


size_t	ft_arraylen(char **array);
t_list	*ft_split_to_list(int *tab, char **array);
void    ft_rev_printflist(t_list *pslist);
void    ft_printflist(t_list *pila, t_list *pileb, size_t lena, size_t lenb);
void    ft_ps_a(t_list *lst);
t_list  *ft_ps_lstnew(int content);
t_list  *ft_ps_lstlast(t_list *lst);
t_list  *ft_ps_lstfirst(t_list *lst);
void    ft_assign_top_bot(t_list *pslist);
char    **ft_ps_arg_split(int argc, char **argv);
int 	ft_ps_check_digit(char **array);
int 	*ft_array_to_tab(char **array);
int 	ft_ps_check_int(char **array, int *tab);
int 	ft_ps_check_double(int *tab, int arraylen);
int		ft_ps_check_error(char **array, int *tab, int argc);
void    ft_ps_index(int *tab, t_list **ps_list);
void    ft_sa(t_list **pile);
void	ft_sb(t_list **pile);
void	ft_ss(t_list **pilea, t_list **pileb);
void	ft_ra(t_list **pile);
void	ft_rb(t_list **pile);
void	ft_rr(t_list **pilea, t_list **pileb);
void	ft_rra(t_list **pile);
void	ft_rrb(t_list **pile);
void	ft_rrr(t_list **pilea, t_list **pileb);
void	ft_pa(t_list **pile_a, t_list **pile_b);
void	ft_pb(t_list **pile_a, t_list **pile_b);





char		**ft_split(char *s, char c);
int			ft_isdigit(int c);
long int	ft_atoilong(const char *str);
int			ft_atoi(const char *str);
int			ft_intlen(int x);
char		*ft_itoa(int nb);
int			ft_strcmp(char *str1, char *str2);






#endif