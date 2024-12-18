#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return (i);
}

char *read_line(int fd, char *buffer, char *remainder)
{
    int bytes_read;
    char *temp;

    if (!remainder)
        remainder = ft_strdup("");
    bytes_read = 1;
    while (!ft_strchr(remainder, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(remainder);
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(remainder, buffer);
        free(remainder);
        remainder = temp;
    }
    free(buffer);
    return (remainder);
}

char *get_new_line(char *buffer)
{
    char *line;
    int i;
    int new_line;

    new_line = found_new_line(buffer);
    i = 0;
    if (!buffer[i])
        return (NULL);
    while (buffer[i] && buffer[i] != '\n')
        i++;
    line = malloc(sizeof(char) * (i + 1 + new_line));
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char *get_next_line(int fd)
{
    static char *remainder;
    char *new;
    char *line;
    char *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return (NULL);
    }
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    remainder = read_line(fd,buffer, remainder);
    if (remainder == NULL)
        return (NULL);
    line = get_new_line(remainder);
    remainder = get_new_buffer(remainder);
    return (line);
}
