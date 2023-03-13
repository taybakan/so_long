/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:58:03 by taybakan          #+#    #+#             */
/*   Updated: 2023/03/14 01:18:26 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mapexit(t_data *data)
{
	int	i;

	mlx_clear_window(data->mlx, data->mlx_window);
	mlx_destroy_image(data->mlx, data->img[0]);
	mlx_destroy_image(data->mlx, data->img[1]);
	mlx_destroy_image(data->mlx, data->img[2]);
	mlx_destroy_image(data->mlx, data->img[3]);
	mlx_destroy_image(data->mlx, data->img[4]);
	i = 0;
	while (t_map.map && t_map.map[i])
		free(t_map.map[i++]);
	free(t_map.map);
	exit(0);
}

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
	t_data	*data;
	int		i;

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
	data = ft_window();
	ft_render(data);
	mlx_hook(data->mlx_window, 17, (1L << 2), ft_mapexit, &data);
	mlx_hook(data->mlx_window, 2, (1L << 0), ft_keypress, &data);
	mlx_loop(data->mlx);
	return (0);
}
