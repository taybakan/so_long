#include "so_long.h"

void    ft_render(t_data *data)
{
	int	x;
	int y;

	x = -1;
	while (++x < t_map.lenght)
	{
		y = -1;
		while (++y < t_map.width)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[4], y * 64, x * 64);
			if (t_map.map[x][y] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[3], y * 64, x * 64);
			else if (t_map.map[x][y] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[1], y * 64, x * 64);
			else if (t_map.map[x][y] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[2], y * 64, x * 64);
			else if (t_map.map[x][y] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[0], y * 64, x * 64);
		}
	}
}

void    ft_getstripes(t_data *data)
{
	data->img = (void **)malloc(sizeof(void *) * 5);
	data->img[0] = mlx_xpm_file_to_image(data->mlx, "s/dog.xpm", &data->imgx, &data->imgy);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, "s/ball.xpm", &data->imgx, &data->imgy);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, "s/girl.xpm", &data->imgx, &data->imgy);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, "s/tree.xpm", &data->imgx, &data->imgy);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, "s/grass.xpm", &data->imgx, &data->imgy);   
}

void    ft_window(void)
{
	t_data  *data;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, t_map.width * 64, t_map.lenght * 64, "so_long");
	ft_getstripes(data);
	ft_render(data);
	mlx_loop(data->mlx);
}