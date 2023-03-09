/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:18:56 by taybakan          #+#    #+#             */
/*   Updated: 2023/03/09 17:09:50 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./src/libft/libft.h"
# include "./src/ft_printf/ft_printf.h"
# include "./src/gnl/get_next_line.h"
# include "./src/mlx/mlx.h"
# include <fcntl.h>

struct s_map
{
    char    **map;
    int     l_cnt;
    int     w_cnt;
    int		p_cnt;
	int     e_cnt;
    int     c_cnt;
}    t_map;

void    ft_create_map(char  *str);
char    *ft_map_name(char *str);
void	ft_getmap(char *map_name);
int		ft_count(char c);
void	ft_checkmap(void);
#endif
