/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:19:17 by taybakan          #+#    #+#             */
/*   Updated: 2023/01/12 07:10:47 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_and_create(int fd, char *str);
char	*ft_create(char *str);

size_t	ft_gnllen(const char *str);
char	*ft_gnljoin(char *s1, char *s2);
char	*ft_gnlchr(const char *str, int c);
size_t	ft_gnlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_free(void *str);

#endif
