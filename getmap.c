/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:15:35 by taybakan          #+#    #+#             */
/*   Updated: 2023/03/13 01:00:37 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkmap(void)
{
	int	i;
	int	j;

	i = j = t_map.p_cnt = t_map.e_cnt = t_map.c_cnt =  0;
	while (t_map.map[i] != NULL)
	{
		while (t_map.map[i][j] != '\n' && t_map.map[i][j] != '\0')
		{
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
	ft_printf("%d\n%d\n%d\n", t_map.p_cnt, t_map.e_cnt, t_map.c_cnt);
	if (t_map.p_cnt != 1 || t_map.e_cnt != 1 || t_map.c_cnt < 1)
		exit(1);
}

void	ft_readmap(void)
{
	char	*str;
	int		fd;
	int		i;
	int		j;

	fd = open(t_map.name, O_RDONLY);
	i = 0;
	j = t_map.lenght;
	t_map.map = malloc(sizeof(char *) * (t_map.lenght + 1));
	while (j > 0)
	{
		str = get_next_line(fd);
		t_map.map[i] = str;
		i++;
		j--;
	}
	ft_printf("%s", t_map.map[0]);
	ft_printf("%s", t_map.map[1]);
	ft_printf("%s", t_map.map[2]);
	ft_printf("%s", t_map.map[3]);
	t_map.map[i] = NULL;
	close(fd);
}

void	ft_getdimensions(void)
{
	char	*line;
	int	fd;
	int	i;
	int	j;

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
			if(j != t_map.width)
				exit(1);
		}
		i++;
	}
	close(fd);
	t_map.width -= 1;
	t_map.lenght = i;
	//ft_printf("%d\n%d\n",  t_map.lenght, t_map.width);
	if (t_map.lenght < 3 || t_map.width < 3)
		exit(1);
}

void	ft_getmap(void)
{
	ft_getdimensions();
	ft_readmap();
	ft_checkmap();
}
