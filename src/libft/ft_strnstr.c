/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:48:26 by taybakan          #+#    #+#             */
/*   Updated: 2022/07/03 11:26:42 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *neddle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (!(*neddle))
		return ((char *)haystack);
	while (h < len && haystack[h])
	{
		n = 0;
		while (haystack[h + n] == neddle[n] && h + n < len && haystack[h + n])
		{
			if (!neddle[n + 1])
				return ((char *)(haystack + h));
			n++;
		}
		h++;
	}
	return (NULL);
}
