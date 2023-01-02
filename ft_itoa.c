/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:28:13 by lsohler           #+#    #+#             */
/*   Updated: 2022/12/12 15:28:52 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_intlen(int x)
{
	int	y;
	int	i;

	i = 0;
	y = x;
	if (x < 0)
		i++;
	while (y != 0)
	{
		y /= 10;
		i++;
	}
	if (x == 0)
		i = 1;
	return (i);
}

char	*ft_itoa(int nb)
{
	char		*str;
	int			i;
	int			sign;
	long int	x;

	x = nb;
	sign = x;
	i = ft_intlen(x) - 1;
	str = malloc(sizeof(char) * ft_intlen(x) + 1);
	if (!str)
		return (NULL);
	if (x < 0)
		x *= -1;
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = x % 10 + 48;
		x /= 10;
		i--;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}