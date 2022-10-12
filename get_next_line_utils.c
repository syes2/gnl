/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sushu <sushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:09:28 by seungbae          #+#    #+#             */
/*   Updated: 2022/10/12 16:29:22 by sushu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// void	ft_strcpy(char *dst, const char *src)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (src[i])
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (c == '\0')
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

// void	ft_bzero(char *s, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (n > i)
// 		s[i++] = 0;
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		s1_len;
// 	int		s2_len;
// 	int		i;
// 	char	*res;

// 	s2_len = 0;
// 	while (s2[s2_len] && s2[s2_len] != '\n')
// 		s2_len++;
// 	if (s2[s2_len] == '\n')
// 		s2_len++;
// 	res = malloc(ft_strlen(s1) + s2_len + 1);
// 	if (!res)
// 		return (NULL);
// 	ft_strcpy(res, s1);
// 	s1_len = ft_strlen(res);
// 	i = 0;
// 	while (i < s2_len)
// 	{
// 		res[s1_len + i] = s2[i];
// 		i++;
// 	}
// 	res[s1_len + i] = 0;
// 	free(s1);
// 	return (res);
// }

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (c == '\0')
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
		str[i++] = s2[j++];
	free (s1);
	str[i] = '\0';
	return (str);
}