/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sushu <sushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:09:32 by seungbae          #+#    #+#             */
/*   Updated: 2022/09/28 16:30:53 by sushu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_fd(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			ret;
	size_t		len;

	if (buf[0] == '\0')
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (ret < 1)
		{
			if (ret == -1)
				ft_bzero(*line, 1);
			return (0);
		}
	}
	len = 0;
	while (buf[len] && buf[len] != '\n')
		len++;
	if (buf[len] == '\n')
		len++;
	*line = ft_strjoin(*line, buf);
	ft_strcpy(buf, &buf[len]);
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
	if (!line[0])
	{
		free (line);
		return (0);
	}
	return (line);
}