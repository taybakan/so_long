#include "so_long.h"

void     ft_move(int m_x, int m_y, t_data *data)
{
    if (t_map.map[t_map.p_y + m_y][t_map.p_x + m_x] == '1')
        return ;
    else if (t_map.map[t_map.p_y + m_y][t_map.p_x + m_x] == 'C')
        t_map.basket++;
    else if (t_map.map[t_map.p_y + m_y][t_map.p_x + m_x] == 'E')
    {
        if (t_map.basket == t_map.c_cnt)
        {
            ft_printf("move count: %d\n", ++t_map.moves);
            ft_mapexit(data);
        }
        else
            return ;
    }
    t_map.map[t_map.p_y][t_map.p_x] = '0';
    t_map.p_y += m_y;
    t_map.p_x += m_x;
    t_map.map[t_map.p_y][t_map.p_x] = 'P';
    ft_printf("move count: %d\n", ++t_map.moves);
    mlx_clear_window(data->mlx, data->mlx_window);
    ft_window();
}

int     ft_keypress(int key, t_data *data)
{
	if (key == KEY_W)
		ft_move(-1, 0, data);
	if (key == KEY_A)
		ft_move(0, -1, data);
	if (key == KEY_S)
		ft_move(1, 0, data);
	if (key == KEY_D)
		ft_move(0, 1, data);
	if (key == KEY_ESC)
		ft_mapexit(data);
	return (1);
}