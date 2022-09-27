/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sushu <sushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:10:37 by seungbae          #+#    #+#             */
/*   Updated: 2022/09/27 13:23:47 by sushu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

size_t	ft_strlen(const char *s);
static int	ft_read_fd(int fd, char **line);
size_t	ft_strlen(const char *s);
void	ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(char *s, size_t n);
char	*ft_strjoin(char *s1, char *s2);


#endif