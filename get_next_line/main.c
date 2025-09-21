#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
    char    *line;
    int fd = open("test.txt", O_RDWR, 0777);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}