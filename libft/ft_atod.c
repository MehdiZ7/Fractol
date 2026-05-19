/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:11:36 by mzouhir           #+#    #+#             */
/*   Updated: 2025/12/23 15:02:35 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*first_check(const char *str, int *sign)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

double	ft_atod(const char *str)
{
	long	integer;
	double	fract;
	double	pow;
	int		sign;

	integer = 0;
	fract = 0;
	pow = 1;
	sign = 1;
	str = first_check(str, &sign);
	while (*str >= '0' && *str <= '9')
		integer = integer * 10 + *str++ - '0';
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		pow /= 10;
		fract = fract + (*str++ - '0') * pow;
	}
	return ((integer + fract) * sign);
}
