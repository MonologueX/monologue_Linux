#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char *str;
    mkfifo(str, 0644);
    int fd = open(str, O_WRONLY);
    {
        perror("open errror");
        return -1;
    }
    sleep(30);
    close(fd);
    return 0;
}
