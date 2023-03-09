/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:58:03 by taybakan          #+#    #+#             */
/*   Updated: 2023/03/09 14:02:53 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	char	*map_name;
	if (argc != 2)
	{
//		ft_error("argcount");
		return (1);
	}
	map_name = ft_map_name(argv[1]);
	ft_getmap(map_name);
	ft_printf("%s\n", map_name);
	ft_checkmap();
	return (0);
}
