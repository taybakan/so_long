/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:05:54 by taybakan          #+#    #+#             */
/*   Updated: 2022/07/03 14:13:37 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_converter(int n, int digit, int sign, int abs)
{
	char	*num;
	int		i;
	int		last;

	last = digit + sign - 1;
	i = 0;
	num = (char *)malloc(sizeof(char) * (digit + sign + 1));
	if (!num)
		return (NULL);
	if (sign)
		num[i++] = '-';
	while (i < (digit + sign))
	{
		num[digit + sign - 1] = (n % 10) + 48;
		n /= 10;
		digit--;
	}
	if (abs == -2147483648)
		num[last] = '8';
	num[++last] = 0;
	return (num);
}

char	*ft_itoa(int n)
{
	int		digit;
	int		sign;
	int		cur;
	char	*num;
	int		abs;

	abs = n;
	if (n == -2147483648)
		n += 1;
	digit = 1;
	sign = 1;
	if (n >= 0)
		sign = 0;
	else
		n *= -1;
	cur = n;
	while (cur / 10 > 0 && digit++)
		cur /= 10;
	num = ft_converter(n, digit, sign, abs);
	return (num);
}
