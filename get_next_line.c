/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sushu <sushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:09:32 by seungbae          #+#    #+#             */
/*   Updated: 2022/09/27 13:21:04 by sushu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_fd(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int			ret;
	size_t		len;

	if (buff[0] == '\0')
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		if (ret < 1)
		{
			if (ret == -1)
				ft_bzero(*line, 1);
			return (0);
		}
	}
	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	if (buff[len] == '\n')
		len++;
	*line = ft_strjoin(*line, buff);
	ft_strcpy(buff, &buff[len]);
	return (1);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (!ft_strchr(line, '\n'))
		if (!ft_read_fd(fd, &line))
			break ;
	if (line[0] == '\0')
	{
		free (line);
		return (0);
	}
	return (line);
}