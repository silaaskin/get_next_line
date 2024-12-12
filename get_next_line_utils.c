/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:24:37 by saskin            #+#    #+#             */
/*   Updated: 2024/12/12 20:13:39 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*newsrc;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	newsrc = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (newsrc == NULL)
		return (NULL);
	while (s1[i])
	{
		newsrc[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newsrc[j + i] = s2[j];
		j++;
	}
	newsrc[i + j] = '\0';
	return (newsrc);
}
char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*newsrc;
	int		l;

	i = 0;
	l = 0;
	while (s1[l])
		l++;
	newsrc = (char *)malloc((l + 1) * sizeof(char));
	if (!(newsrc))
		return (NULL);
	while (s1[i])
	{
		newsrc[i] = s1[i];
		i++;
	}
	newsrc[i] = '\0';
	return (newsrc);
}
