/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sushu <sushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:09:32 by seungbae          #+#    #+#             */
/*   Updated: 2022/10/12 16:29:23 by sushu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buf)
{
	char	*str;
	int		rsize;

	rsize = 1;
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (!ft_strchr(buf, '\n') && rsize != 0)
	{
		rsize = read(fd, str, BUFFER_SIZE);
		if (rsize == -1)
		{
			free(str);
			return (NULL);
		}
		str[rsize] = '\0';
		buf = ft_strjoin(buf, str);
	}
	free(str);
	return (buf);
}

char	*get_line(char *buf)
{
	char	*str;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (!buf[0])
		return (NULL);
	while (buf[j] && buf[j] != '\n')
		j++;
	str = (char *)malloc(sizeof(char) * (j + 2));
	if (!str)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
	{
		str[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		str[i] = buf[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*backup(char *buf)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buf[i])
		str[j++] = buf[i++];
	str[j] = '\0';
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buf = read_line(fd, buf);
	if (!buf)
	{
		free (buf);
		return (NULL);
	}
	line = get_line(buf);
	buf = backup(buf);
	return (line);
}

// #include "get_next_line.h"

// static int	ft_read_fd(int fd, char **line)
// {
// 	static char	buf[BUFFER_SIZE + 1];
// 	int			ret;
// 	size_t		len;

// 	if (!buf[0])
// 	{
// 		ret = read(fd, buf, BUFFER_SIZE);
// 		if (ret < 1)
// 		{
// 			if (ret == -1)
// 				ft_bzero(*line, 1);
// 			return (0);
// 		}
// 		buf[ret] = '\0';
// 	}
// 	len = 0;
// 	while (buf[len] && buf[len] != '\n')
// 		len++;
// 	if (buf[len] == '\n')
// 		len++;
// 	*line = ft_strjoin(*line, buf);
// 	ft_strcpy(buf, &buf[len]);
// 	return (1);
// }

// char	*get_next_line(int fd)
// {
// 	char	*line;

// 	line = malloc(1); 
// 	if (!line)
// 		return (NULL);
// 	line[0] = '\0';
// 	while (!ft_strchr(line, '\n'))
// 		if (!ft_read_fd(fd, &line))
// 			break ;
// 	if (!line[0])
// 	{
// 		free (line);
// 		return (0);
// 	}
// 	return (line);
// }