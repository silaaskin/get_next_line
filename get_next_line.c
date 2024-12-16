#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return (i);
}

char *read_line(int fd, char *str, char *remainder)
{
    ssize_t bytes_read;
    char *newstr;
    char *new;

    if (!remainder)
        remainder = ft_strdup("");
    newstr = NULL;
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, str, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(str);
            return (NULL);
        }
        str[bytes_read] = '\0';

        newstr = ft_strjoin(remainder, str);
        free(remainder);
        remainder = newstr;

        if (ft_strchr(remainder, '\n'))
        {

            new = ft_substr(remainder, 0, remainder - ft_strchr(remainder, '\n'));
            remainder = ft_strdup(ft_strchr(remainder, '\n'));
            free(newstr);
            return (new);
        }
    }

    if (bytes_read == 0 && ft_strlen(remainder) > 0)
    {
        new = ft_strdup(remainder);
        free(remainder);
        return (new);
    }

    free(remainder);
    return (NULL);
}

char *get_next_line(int fd)
{
    static char *remainder;
    char *str;
    char *newstr;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    str = malloc(BUFFER_SIZE + 1);
    if (!str)
        return (NULL);

    newstr = read_line(fd, str, remainder);
    free(str); //
    return (newstr);
}
