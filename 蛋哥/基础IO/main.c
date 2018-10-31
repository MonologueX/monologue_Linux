/////////////////////////////// 
// 文件名称:
// 文件描述:
// 编译环境:Linux
// 作者相关:心文花雨 
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd = open("file", O_WRONLY|O_CREAT, 0644);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    const char* msg = "hello word\n";
    int count = 5;
        
    while (count--)
    {
        write(fd, msg, strlen(msg));
    }

    close(fd);
    return 0;
}
