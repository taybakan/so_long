/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:58:03 by taybakan          #+#    #+#             */
/*   Updated: 2023/03/13 01:11:36 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		exit(1);
	t_map.name = ft_strtrim(argv[1], "\t\n ");
	//ft_printf("%s\n", t_map.name);
	i = ft_strlen(t_map.name) - 4;
	//ft_printf("%d\n", i);
	if (ft_strncmp(t_map.name + i, ".ber", 4) != 0)
		exit(1);
	//ft_printf("bura");
	ft_getmap();
	ft_printf("%s", t_map.map[0]);
	ft_printf("%s", t_map.map[1]);
	ft_printf("%s", t_map.map[2]);
	ft_printf("%s", t_map.map[3]);
	return (0);
}
