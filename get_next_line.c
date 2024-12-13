/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:24:40 by saskin            #+#    #+#             */
/*   Updated: 2024/12/13 17:52:34 by saskin           ###   ########.fr       */
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
char *read_line(int fd, char *str, char *remainder)
{
    int i = 0;
    char *newstr;
    char *new;
    ssize_t bytes_read;
    bytes_read = 1;
if(!remainder)
    remainder = ft_strdup("");
while(bytes_read != 0)
{
 bytes_read = read(fd, str, BUFFER_SIZE);
 if(bytes_read == -1)
{
    free(str);
    return NULL;
}
if(bytes_read == 0)
    break;
newstr = ft_strjoin(remainder, str);
if(ft_strchr(remainder, '\n'))
    return remainder;
if((ft_strchr(str, '\n')))
{
    remainder = ft_strchr(str, '\n') + 1;
    new = ft_substr(newstr, 0, ft_strlen(newstr) - ft_strlen(remainder));
}
}
return new;
}
char *get_next_line(int fd)
{
    char *str;
    static char *remainder;
    char *newstr;
    char *new;
    if(fd <= 0 || BUFFER_SIZE <= 0)
        return NULL;
    str = malloc( BUFFER_SIZE + 1);
    if(!str)
        return NULL;
    newstr =read_line(fd, str, remainder);
    return newstr;
}
int main()
{
    int fd = open("sila.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
}
