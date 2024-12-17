#include "get_next_line.h"

int main() 
{


    int fd = open("sila.txt", O_RDONLY);

    char *buf = get_next_line(fd);
    char *buf1 = get_next_line(fd);
    char *buf2 = get_next_line(fd);
    char *buf3 = get_next_line(fd);
    char *buf4 = get_next_line(fd);
    char *buf5 = get_next_line(fd);

    printf("%s", buf);
    printf("%s", buf1);
    printf("%s", buf2);
    printf("%s", buf3);
    printf("%s", buf4);
    printf("%s", buf5);
    free(buf);
    free(buf1);
    free(buf2);

    // char *line;

    // int fd = open("sila.txt", O_RDONLY);
    // while ((line = get_next_line(fd)) != NULL)
    // {
    //     printf("%s\n", line);
    //     free(line);
    // }
}
