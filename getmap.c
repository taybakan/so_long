/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:15:35 by taybakan          #+#    #+#             */
/*   Updated: 2023/03/08 17:39:45 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_map(char	*str)
{
	int		i;

	i = 0;
	t_map.map = malloc((sizeof(char *)) * (t_map.l_cnt + 1));
	t_map.map[i] = str;
	ft_printf("%s", t_map.map[i]);
	i++;
}

void	ft_getmap(char	*map_name)
{
	int		fd;
	int		i;
	int		w;
	char	*line;

	i = 0;
	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	t_map.w_cnt = ft_strlen(line);
	while (line)
	{
		i++;
		ft_create_map(line);
		free(line);
		line = get_next_line(fd);
		if (!line)
		{
			w = ft_strlen(line);
//			if (w != tmap.w_cnt)
//				ft_error("map_error");
		}
	}
	t_map.l_cnt = i;
	close(fd);
	ft_printf("%d\n", t_map.l_cnt);
	ft_printf("%d\n", t_map.w_cnt);
}

char	*ft_map_name(char *str)
{
	int		i;
	char	*map_name;
	char	*to_trim;

	to_trim = "\t\n ";
	map_name = ft_strtrim(str, to_trim);
	i = ft_strlen(map_name);
	i = i - 4;
	if (ft_strncmp((map_name + i), ".ber", 4) != 0)
	{
//		ft_error("wrong map name");
		return ("NULL");
	}
	return (map_name);
}
