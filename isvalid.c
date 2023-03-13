/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:56:16 by taybakan          #+#    #+#             */
/*   Updated: 2023/03/13 20:13:57 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_mapdup(void)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (t_map.lenght + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (t_map.map[i])
	{
		copy[i] = ft_strdup(t_map.map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	ft_hike(char **map, int c, int r)
{
	map[r][c] = '*';
	if (map[r + 1][c] != '1' && map[r + 1][c] != '*')
		ft_hike(map, c, r + 1);
	if (map[r - 1][c] != '1' && map[r - 1][c] != '*')
		ft_hike(map, c, r - 1);
	if (map[r][c + 1] != '1' && map[r][c + 1] != '*')
		ft_hike(map, c + 1, r);
	if (map[r][c - 1] != '1' && map[r][c - 1] != '*')
		ft_hike(map, c - 1, r);
}

void     ft_checkpath(void)
{
	char	**map;
	int		j;
	int		i;

	map = ft_mapdup();
	ft_hike(map, t_map.p_y, t_map.p_x);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '*' && map[i][j] != '\n' &&
			map[i][j] != '1' && map[i][j] != '0')
                ft_maperror(2);
		}
	}
}