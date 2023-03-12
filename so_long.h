/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:18:56 by taybakan          #+#    #+#             */
/*   Updated: 2023/03/12 23:05:15 by taybakan         ###   ########.fr       */
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
    char	*name;
    int     lenght;
    int		width;
	int     p_cnt;
    int     e_cnt;
	int		c_cnt;
}    t_map;

void	ft_getmap(void);
void	ft_getdimensions(void);
void	ft_readmap(void);
void	ft_checkmap(void);

#endif
