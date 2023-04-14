/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:13 by lsohler@stu       #+#    #+#             */
/*   Updated: 2023/04/14 12:48:43 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"

# define INT_MIN	-2147483648
# define INT_MAX	2147483647

typedef struct s_list
{
	int				index;
	int				pos;
	int				cost_a;
	int				cost_b;
	int				target_pos;
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_data
{
	int		index;
	int		pos;
	int		len;
	int		lena;
	int		lenb;
	int		cost_a;
	int		cost_b;
	int		x;
	int		y;
	int		target_pos;
	int		target_index;
}				t_data;

size_t		ft_arraylen(char **array);
t_list		*ft_split_to_list(int *tab, char **array);
char		**ft_ps_arg_split(int argc, char **argv);
int			*ft_array_to_tab(char **array);
int			ft_ps_check_error(char **array, int *tab, int argc);
void		ft_ps_index(int *tab, t_list **ps_list, size_t len);
void		ft_sa(t_list **pile);
void		ft_sb(t_list **pile);
void		ft_ss(t_list **pilea, t_list **pileb);
void		ft_ra(t_list **pile);
void		ft_rb(t_list **pile);
void		ft_rr(t_list **pilea, t_list **pileb);
void		ft_rra(t_list **pile);
void		ft_rrb(t_list **pile);
void		ft_rrr(t_list **pilea, t_list **pileb);
void		ft_pa(t_list **pile_a, t_list **pile_b, t_data *ps_data);
void		ft_pb(t_list **pile_a, t_list **pile_b, t_data *ps_data);
void		checker_pa(t_list **pile_a, t_list **pile_b, t_data *ps_data);
void		checker_pb(t_list **pile_a, t_list **pile_b, t_data *ps_data);
void		checker_rrr(t_list **pile_a, t_list **pile_b);
void		checker_rr(t_list **pile_a, t_list **pile_b);
void		checker_ss(t_list **pile_a, t_list **pile_b);
void		ft_r_rotate(t_list **pslist);
void		ft_rotate(t_list **pslist);
void		ft_swap(t_list **pile);
size_t		ft_push(t_list **pile_s,
				t_list **pile_d, size_t len_s, size_t len_d);
int			ps_sorted_check(t_list *pile_a, t_data *ps_data);
int			ps_where_is_last_sorted(t_list *pile_a, t_data *ps_data);
void		ps_rotate_to_find(t_list **pile, t_data *ps_data);
t_data		*ps_new_data(size_t lenght);
void		ps_data_range(t_data *ps_data, size_t range_x, size_t range_y);
void		ft_pre_sort(t_list **pile_a, t_list **pile_b, t_data *ps_data);
void		ps_post_sort_main(t_list **pile_a,
				t_list **pile_b, t_data *ps_data);
void		ps_sort_3(t_list **pile_a, t_data *ps_data);
void		ps_free(t_list **pile_a, t_data *ps_data);
void		free_split(char **array, int argc);
char		**ft_split(char *s, char c);
int			ft_isdigit(int c);
long int	ft_atoilong(const char *str);
int			ft_atoi(const char *str);
int			ft_intlen(int x);
char		*ft_itoa(int nb);
int			ft_strcmp(char *str1, char *str2);
int			ft_abs(int nb);
void		assign_cost(t_list **pile_b, t_data *data);
void		get_target_pos(t_list **pile_a, t_list **pile_b, t_data *data);
void		do_best_move(t_list **pile_a, t_list **pile_b, t_data *data);
void		do_move(t_list **pile_a, t_list **pile_b, t_data *data);
void		rotate_to_first(t_list **pile_a, t_data *data);
void		assign_pos(t_list **list, int len);
int			free_tab_array(char **array, int *tab, int argc, int error);
void		pushswap(t_list **pile_a,
				t_list **pile_b, t_data *ps_data);

#endif