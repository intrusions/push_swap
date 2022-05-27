/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:50:43 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/27 23:44:36 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
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
		if (r * neg > 2147483647)
			return (-1);
		else if (r * neg < -2147483648)
			return (0);
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

void	ft_print_stack(int *stack, int len)
{
	for(int i = 0; i < len; i++)
		printf("%d\n", stack[i]);
	printf("----------\n");
}

void	ft_fill_stack(int *stack, int len, char **argv)
{
	int	i;

	i = 0;
	while (i < len)
	{
		stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}