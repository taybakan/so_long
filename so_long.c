/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:58:03 by taybakan          #+#    #+#             */
/*   Updated: 2023/03/13 22:03:41 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void    ft_maperror(int i)
{
	if (i == 0)
    	write(2, "Error!\nusage: ./solong [map].ber\n", 32);
	if (i == 1)
    	write(2, "Error!\nthere is something wrong with the map\n", 45);
	if (i == 2)
    	write(2, "Error!\nno valid path\n", 21);
	if (i == 3)
		write(2, "bura\n", 5);
    exit(1);
}

int main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		ft_maperror(0);
	t_map.name = ft_strtrim(argv[1], "\t\n ");
	i = ft_strlen(t_map.name) - 4;
	if (ft_strncmp(t_map.name + i, ".ber", 4) != 0)
		ft_maperror(0);
	ft_getdimensions();
	ft_readmap();
	ft_checkmap();
	ft_checkpath();
	ft_window();
	ft_printf("%s", t_map.map[0]);
	ft_printf("%s", t_map.map[1]);
	ft_printf("%s", t_map.map[2]);
	ft_printf("%s", t_map.map[3]);
	return (0);
}
