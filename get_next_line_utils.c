#include "get_next_line.h"
char *ft_strjoin(char *s1, char *s2)
{
	int s1len;
	int s2len;
	char *newsrc;
	int i;
	int j;

	i = 0;
	j = 0;
	newsrc = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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
char *ft_strchr(const char *s, int c)
{
	unsigned int i;

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
char *ft_strdup(const char *s1)
{
	int i;
	char *newsrc;
	int l;

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
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *p;

	if (s == NULL)
		return (NULL);
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s + start, len + 1);
	return (p);
}
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
