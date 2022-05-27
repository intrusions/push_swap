/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:40:37 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/28 00:37:52 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define _STACK_A 1
# define _STACK_B 0

//struct
typedef struct s_data
{
	int *stack_a;
	int *stack_b;
	int len_a;
	int len_b;
}   t_data;

//utils
int     ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_fill_stack(int *stack, int len, char **argv);
void	ft_print_stack(int *stack, int len);

//operations
void    ft_swap_sa_sb(int *stack, int len, int what_stack);
void    ft_swap_ss(int *stack_a, int *stack_b, int len_a, int len_b);
void    ft_push_pa(t_data *data);

//utils operation
int		ft_delete_top_pa(t_data *data);
int		ft_add_top_pa(t_data *data);

#endif