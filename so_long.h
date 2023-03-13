/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:18:56 by taybakan          #+#    #+#             */
/*   Updated: 2023/03/14 01:03:58 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./src/libft/libft.h"
# include "./src/ft_printf/ft_printf.h"
# include "./src/gnl/get_next_line.h"
# include "./src/mlx/mlx.h"
# include <fcntl.h>

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

struct s_map
{
    char    **map;
    char	*name;
    int     lenght;
    int		width;
	int     p_cnt;
    int     e_cnt;
	int		c_cnt;
    int     basket;
    int		p_x;
    int		p_y;
    int     e_x;
    int     e_y;
}    t_map;

typedef struct s_data
{
    void    *mlx;
    void    *mlx_window;
    void    **img;
    int     imgx;
    int     imgy;
    int     position_x;
    int     position_y;
}    t_data;

void	ft_getmap(void);
void	ft_getdimensions(void);
void	ft_readmap(void);
void	ft_checkmap(void);
void	ft_getplayer_getexit(char c, int x, int y);
void	ft_checkpath(void);
void	ft_maperror(int c);
char	**ft_mapdup(void);
void	ft_hike(char **map, int c, int r);
void    ft_window(void);
void    ft_getstripes(t_data *data);
void    ft_render(t_data *data);
int     ft_keypress(int key, t_data *data);
int     ft_move(int m_x, int m_y, t_data *data);
void	ft_exit(t_data *data);
void    

#endif
