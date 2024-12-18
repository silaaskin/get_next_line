#include "get_next_line.h"
int main()
{
    char *line;
    int fd;
    fd = open("sila.txt", O_RDONLY, 0644);
    while((line = get_next_line(fd)) != NULL)
    {
        printf("%s",line);
        free(line);
    }
}