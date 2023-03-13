#include "so_long.h"

int     ft_move(int m_x, int m_y, t_data *data)
{
    if (t_map.map[t_map.p_y + m_y][t_map.p_x + m_x] == '1')
        return ;
    else if (t_map.map[t_map.p_y + m_y][t_map.p_x + m_x] == 'C')
        t_map.basket++;
    else if ()

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
		ft_game(data);
	return (1);
}