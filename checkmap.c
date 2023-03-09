/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:35:10 by taybakan          #+#    #+#             */
/*   Updated: 2023/03/09 17:50:23 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h" 

int		ft_count(char c)
{
	int		i;
	int 	j;
	int 	k;

	i = 0;
	k = 0;
	while(*t_map.map[i])
	{
		ft_printf("%s\n", t_map.map[i]);
		j = 0;
		while(t_map.map[i][j] != '\0')
		{
			if(t_map.map[i][j] == c)
			{
				k++;
				ft_printf("burası %d\n", k);
			}
			j++;
		}
		i++;
	}
	return (k);
}
void	ft_checkmap(void)
{
	t_map.p_cnt = ft_count('P');
	t_map.e_cnt	= ft_count('E');
	t_map.c_cnt = ft_count('C');
	ft_printf("%d\n", t_map.p_cnt);
	ft_printf("%d\n", t_map.e_cnt);
	ft_printf("%d\n", t_map.c_cnt);
}

