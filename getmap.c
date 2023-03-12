/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:15:35 by taybakan          #+#    #+#             */
/*   Updated: 2023/03/13 01:52:50 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkmap(void)
{
	int	i;
	int	j;

	i = 0;
	while (t_map.map[i] != NULL)
	{
		j = 0;
		while (t_map.map[i][j] != '\n' && t_map.map[i][j] != '\0')
		{
			if (t_map.map[0][j] != '1' || t_map.map[t_map.lenght - 1][j] != '1' || t_map.map[i][0] != '1' || t_map.map[i][t_map.width - 1] != '1')
				exit(1);
			if (t_map.map[i][j] == 'P')
				t_map.p_cnt += 1;
			else if (t_map.map[i][j] == 'E')
				t_map.e_cnt += 1;
			else if (t_map.map[i][j] == 'C')
				t_map.c_cnt += 1;
			else if (t_map.map[i][j] != '1' && t_map.map[i][j] != '0')
				exit(1);
			j++;
		}
		i++;
	}
	if (t_map.p_cnt != 1 || t_map.e_cnt != 1 || t_map.c_cnt < 1)
		exit(1);
}

void	ft_readmap(void)
{
	int		fd;
	int		i;
	int		j;

	t_map.width -= 1;
	fd = open(t_map.name, O_RDONLY);
	i = 0;
	j = t_map.lenght;
	t_map.map = malloc(sizeof(char *) * (t_map.lenght + 1));
	while (j > 0)
	{
		t_map.map[i] = get_next_line(fd);
		i++;
		j--;
	}
	t_map.map[i] = NULL;
	close(fd);
}

void	ft_getdimensions(void)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	fd = open(t_map.name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit(1);
	t_map.width = ft_strlen(line);
	i = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
		{
			j = ft_strlen(line);
			if (j != t_map.width)
				exit(1);
		}
		i++;
	}
	close(fd);
	t_map.lenght = i;
}

void	ft_getmap(void)
{
	ft_getdimensions();
	ft_readmap();
	ft_checkmap();
}
