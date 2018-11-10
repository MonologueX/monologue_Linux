/////////////////////////////// 
// 文件名称:main.c
// 文件描述:无
// 编译环境:Linux
// 作者相关:心文花雨 
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include <stdio.h>

int main()
{
    const char* msg1 = "hello printf\n";
    const char* msg2 = "hello fwrinte\n";
    const char* msg3 = "hello write\n";

    printf(msg1);
    fwrite(msg2, 1, strlen(msg2), stdout);
    write(1, msg3, strlen(msg3));
    //fork();
    return 0;
}

/////////////////////////////////
//// 写
//
////int main()
////{
////    int fd = open("file", O_WRONLY|O_CREAT, 0644);
////    if (fd < 0)
////    {
////        perror("open");
////        return 1;
////    }
////    const char* msg = "hello word\n";
////    int count = 5;
////        
////    while (count--)
////    {
////        write(fd, msg, strlen(msg));
////    }
////
////    close(fd);
////    return 0;
////}
//
/////////////////////////////////
//// 读
//
//int main()
//{
//    int fd = open("file", O_WRONLY, 0644);
//    if (fd < 0)
//    {
//        perror("open");
//        return 1;
//    }
//    
//    int count = 10;
//    while (count--)
//    {
//        printf("hello word\n");
//        fflush(stdout);
//    }
//    close(fd);
//  //  int fd1 = open("file", O_RDONLY, 0644);
//  //  int fd2 = open("file", O_RDONLY, 0644);
//  //  int fd3 = open("file", O_RDONLY, 0644);
//  //  printf("fd:%d\n", fd);
//  //  printf("fd:%d\n", fd1);
//  //  printf("fd:%d\n", fd2);
//  //  printf("fd:%d\n", fd3);
//////    const char* msg = "hello word\n";
////    int size = strlen(msg);
////    char buf[64];
////    int count = 5;
////    while (count--)
////    {
////        size_t s = read(fd, buf, size);
////        if (s > 0)
////        {
////            buf[s] = 0;
////        }
////        printf("%s", buf);
////    }
////
////    close(fd);
//    return 0;
//}
