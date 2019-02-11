#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char *str= "./main.fifo";
    mkfifo(str, 0644);
    int fd = open(str, O_RDONLY);
    if (fd <0)
    {
        perror("open errror");
        return -1;
    }

    char buff[1024] = {0};
    read(fd, buff, 1024);
    printf("buff:[%s]\n", buff);
    close(fd);
    return 0;
}
