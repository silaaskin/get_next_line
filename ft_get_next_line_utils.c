#include "get_next_line.h"
char	*get_new_buffer(char *buffer)
{
	char	*updated_buffer;
	int		i;
	int		j;

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
int	found_new_line(char *buffer)
{
	int	i;

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