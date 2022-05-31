/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:40:37 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/31 03:28:00 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define _STACK_A 1
# define _STACK_B 0
# define TRUE 1
# define FALSE 0

//struct
typedef struct s_data
{
	int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;
}	t_data;

//utils
int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_fill_stack(int *stack, int len, char **argv);
void	ft_print_stack(int *stack, int len);
int		ft_error(void);
void	ft_init_struct(t_data *data);
int		ft_prepare_stack(t_data *data, int argc, char **argv, int prepare);
void	ft_free_split(char **argv, int argc);
int		ft_count_tab(char **argv);

//parsing
int		ft_parsing(char **argv, int len);
int		ft_isdigit(char c);
int		ft_check_duplicate_and_max(int *stack, int len);
char	**ft_split(char const *str, char c);

//operations
void	ft_swap_sa_sb(int *stack, int len, int what_stack, int print);
void	ft_swap_ss(t_data *data);
int		ft_push_pa(t_data *data);
int		ft_push_pb(t_data *data);
void	ft_rotate_ra_rb(int *stack, int len, int what_stack, int print);
void	ft_rotate_rr(t_data *data);
void	ft_reverse_rra_rrb(int *stack, int len, int what_stack, int print);
void	ft_reverse_rotate_rrr(t_data *data);

//utils operation
int		ft_delete_top_pa(t_data *data);
int		ft_add_top_pa(t_data *data);
int		ft_delete_top_pb(t_data *data);
int		ft_add_top_pb(t_data *data);

//algorythm
int		ft_sort(t_data *data);
int		ft_is_sorted(int *stack, int len);
int		ft_replace_per_index(int *stack, int len);
int		ft_sort_big_stack(t_data *data);
int		ft_sort_small_stack(t_data *data);
void	ft_sort_for_index(int **new_stack, int len);

#endif