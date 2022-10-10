/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sushu <sushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:09:32 by seungbae          #+#    #+#             */
/*   Updated: 2022/09/29 14:15:05 by sushu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buf)
{
	char	*str;
	int		i;

	i = 1;
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (!ft_strchr(buf, '\n') && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		buf = ft_strjoin(buf, str);
	}
	free(str);
	return (buf);
}

char	*get_line(char *str)
{
	char	*s;
	int		l;
	int		i;

	l = 0;
	i = 0;
	if (!str[0])
		return (NULL);
	while (str[l] && str[l] != '\n')
		l++;
	s = (char *)malloc(sizeof(char) * (l + 2));
	if (!s)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
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