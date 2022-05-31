/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:04:11 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/31 02:15:12 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_prepare_stack(t_data *data, int argc, char **argv, int params)
{
	if (argc == 1)
		return (0);
	data->len_a = argc - 1;
	if (!ft_parsing(argv, data->len_a))
		return (0);
	data->stack_a = malloc(sizeof(int) * (data->len_a));
	if (!data->stack_a)
		return (0);
	data->stack_b = malloc(sizeof(int) * (data->len_a));
	if (!data->stack_b)
		return (free(data->stack_a), 0);
	ft_fill_stack(data->stack_a, data->len_a, argv);
	if (!ft_check_duplicate_and_max(data->stack_a, data->len_a) && !params)
		return (free(data->stack_a), free(data->stack_b), 0);
	else if (!ft_check_duplicate_and_max(data->stack_a, data->len_a) && params)
		return (free(data->stack_a), free(data->stack_b), \
		ft_free_split(argv, argc), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		params;

	params = 0;
	ft_init_struct(&data);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_count_tab(argv);
		params++;
	}
	if (!ft_prepare_stack(&data, argc, argv, params))
		return (ft_error());
	ft_sort(&data);
	if (!params)
		return (free(data.stack_a), free(data.stack_b), 0);
	else
		return (ft_free_split(argv, argc), \
		free(data.stack_a), free(data.stack_b), 0);
}
