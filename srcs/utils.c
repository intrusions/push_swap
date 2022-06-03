/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:50:43 by jucheval          #+#    #+#             */
/*   Updated: 2022/06/03 02:42:51 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	size_t		i;
	long long	r;
	int			neg;

	i = 0;
	r = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (neg * r);
}

void	ft_putstr(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int	ft_error(void)
{
	ft_putstr("Error\n");
	return (0);
}

void	ft_init_struct(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->len_a = 0;
	data->len_b = 0;
}
