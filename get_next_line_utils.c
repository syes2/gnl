/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sushu <sushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:09:28 by seungbae          #+#    #+#             */
/*   Updated: 2022/09/28 16:06:46 by sushu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
		s[i++] = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*res;

	s2_len = 0;
	while (s2[s2_len] && s2[s2_len] != '\n')
		s2_len++;
	if (s2[s2_len] == '\n')
		s2_len++;
	res = malloc(ft_strlen(s1) + s2_len + 1);
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	s1_len = ft_strlen(res);
	i = 0;
	while (i < s2_len)
	{
		res[s1_len + i] = s2[i];
		i++;
	}
	res[s1_len + i] = 0;
	free(s1);
	return (res);
}




// char	*ft_read(int fd, char *s)
// {
// 	char	*str;
// 	int		i;

// 	i = 1;
// 	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!str)
// 		return (NULL);
// 	while (!ft_strchr(s, '\n') && i != 0)
// 	{
// 		i = read(fd, str, BUFFER_SIZE);
// 		if (i == -1)
// 		{
// 			free(str);
// 			return (NULL);
// 		}
// 		str[i] = '\0';
// 		s = ft_strjoin(s, str);
// 	}
// 	free(str);
// 	return (s);
// }

// char	*ft_write(char *str)
// {
// 	char	*s;
// 	int		l;
// 	int		i;

// 	l = 0;
// 	i = 0;
// 	if (!str[0])
// 		return (NULL);
// 	while (str[l] && str[l] != '\n')
// 		l++;
// 	s = (char *)malloc(sizeof(char) * (l + 2));
// 	if (!s)
// 		return (NULL);
// 	while (str[i] && str[i] != '\n')
// 	{
// 		s[i] = str[i];
// 		i++;
// 	}
// 	if (str[i] == '\n')
// 	{
// 		s[i] = str[i];
// 		i++;
// 	}
// 	s[i] = '\0';
// 	return (s);
// }

// char	*ft_copy(char *s)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	while (s[i] && s[i] != '\n')
// 		i++;
// 	if (!s[i])
// 	{
// 		free(s);
// 		return (NULL);
// 	}
// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
// 	if (!str)
// 		return (NULL);
// 	i++;
// 	j = 0;
// 	while (s[i])
// 		str[j++] = s[i++];
// 	str[j] = '\0';
// 	free(s);
// 	return (str);
// }

// char	*get_next_line(int fd)
// {
// 	char		*str;
// 	static char	*s;

// 	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > 2147483647)
// 		return (NULL);
// 	s = ft_read(fd, s);
// 	if (!s)
// 	{
// 		free (s);
// 		return (NULL);
// 	}
// 	str = ft_write(s);
// 	s = ft_copy(s);
// 	return (str);
// }