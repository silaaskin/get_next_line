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
char *get_new_buffer(char *buffer)
{
	char *updated_buffer;
	int i;
	int j;

	j = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	updated_buffer = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!updated_buffer)
		return (NULL);
	while (buffer[i])
		updated_buffer[j++] = buffer[i++];
	updated_buffer[j] = '\0';
	free(buffer);
	return (updated_buffer);
}
int found_new_line(char *buffer)
{
	int i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
