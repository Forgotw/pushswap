/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:13 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/04/07 15:37:41 by lsohler          ###   ########.fr       */
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
	int			pos;
	int			cost_a;
	int			cost_b;
	int			target_pos;
	int 			content;
	//size_t			len;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef	struct s_data
{
	size_t		index;
	size_t		pos;
	size_t		len;
	size_t		lena;
	size_t		lenb;
	int			cost_a;
	int			cost_b;
	size_t		x;
	size_t		y;
	size_t		target_pos;
	size_t		target_index;
	char		pile;
}				t_data;




size_t	ft_arraylen(char **array);
t_list	*ft_split_to_list(int *tab, char **array);
void    ft_rev_printflist(t_list *pslist);
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
void    ft_ps_index(int *tab, t_list **ps_list, size_t len);
void    ft_sa(t_list **pile);
void	ft_sb(t_list **pile);
void	ft_ss(t_list **pilea, t_list **pileb);
void	ft_ra(t_list **pile);
void	ft_rb(t_list **pile);
void	ft_rr(t_list **pilea, t_list **pileb);
void	ft_rra(t_list **pile);
void	ft_rrb(t_list **pile);
void	ft_rrr(t_list **pilea, t_list **pileb);
void	ft_pa(t_list **pile_a, t_list **pile_b, t_data *ps_data);
void	ft_pb(t_list **pile_a, t_list **pile_b, t_data *ps_data);
int 	ps_sorted_check(t_list *pile_a, t_data *ps_data);
int		ps_where_is_last_sorted(t_list *pile_a, t_data *ps_data);


void	ps_rotate_to_find(t_list **pile, t_data *ps_data);
t_data	*ps_new_data(size_t lenght);
void	ps_data_range(t_data *ps_data, size_t range_x, size_t range_y);
void	ft_pre_sort(t_list **pile_a, t_list **pile_b, t_data *ps_data);
void	ps_post_sort(t_list **pile_a, t_list **pile_b, t_data *ps_data);
int		ps_find(t_data *ps_data, t_list *pile_top, t_list *pile_bot);
void	ps_sort_to_find(t_list **pile_a, t_list **pile_b, t_data *ps_data);

void	ps_post_sort_main(t_list **pile_a, t_list **pile_b, t_data *ps_data);
void	ps_sort_3(t_list **pile_a, t_data *ps_data);
int		ps_find_b(t_data *ps_data, t_list *pile_top, t_list *pile_bot);

void	ps_sort_to_index(t_list **pile_a, t_list **pile_b, t_data *ps_data);
void	ps_post_sort_main2(t_list **pile_a, t_list **pile_b, t_data *ps_data);
void	sort_if_bot_unclear(t_list **pile_a, t_list **pile_b, t_data *ps_data);
void	sort_if_bot_clear(t_list **pile_a, t_list **pile_b, t_data *ps_data);
void	ps_check_for_insert(t_list **pile_a, t_list **pile_b, t_data *ps_data);

void	ps_find_data(t_data *ps_data, size_t i, size_t p);

void ps_free(t_list **pile_a, t_data *ps_data);
void free_split(char **array, int argc);

char		**ft_split(char *s, char c);
int			ft_isdigit(int c);
long int	ft_atoilong(const char *str);
int			ft_atoi(const char *str);
int			ft_intlen(int x);
char		*ft_itoa(int nb);
int			ft_strcmp(char *str1, char *str2);
int			ft_abs(int nb);



void	ft_printflist(t_list *pslist, t_list *pslist2, size_t lena, size_t lenb);


void	assign_cost(t_list **pile_b, t_data *data);
void	get_target_pos(t_list **pile_a, t_list **pile_b, t_data *data);
void	do_best_move(t_list **pile_a, t_list **pile_b, t_data *data);
void	do_move(t_list **pile_a, t_list **pile_b, t_data *data);








#endif