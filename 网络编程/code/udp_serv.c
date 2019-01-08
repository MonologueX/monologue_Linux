/***********************************
 * 文件名称: main.c
 * 文件描述: 
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <error.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    /*
     * 函数名: int socket(int dointmain, int type, int protocol);
     * 函数功能: 创建套接字
     * 参数: domain:地址域      AF_INET 使用IPV4网络协议
     *       type: 套接字类型
     *       SOCK_STREAM 流式套接字     默认协议tcp
     *       SOCK_DGRAM  数据报套接字   默认协议udp
     * protocol:协议
     * 返回值:套接字描述符(非负整数)    失败:-1
    */
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd <0)
    {
        perror("scoket error");
        return -1;
    }
    /*
     * 函数名: int bind(int sockfd, struct sockaddr *my_addr, socklen_t addrlen);
     * 函数功能: 为套接字绑定地址信息
     * 参数: sockfd:套接字描述符
     *       addr:地址信息
     *          使用sockaddr_in定义，使用时进行类型强转
     *       adrlen:地址信息长度
     * 返回值: 0     失败:-1
    */
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    /*
     * 函数名: uint16_t htons(uint16_t hostshort);
     * 函数功能: uint16_t类型的数据从主机字节序转换为网络字节序
    */
    addr.sin_port = htons(9000);
    /*
     * 函数名: int32_t htonl(uint32_t hostlong);
     * 函数功能: uint32_t类型的数据从主机字节序转换为网络字节序
    */
    // addr.sin_addr.s_addr = htonl(0xc0a8f18b);
    /*
     * 函数名: in_addr_t inet_addr(const char *cp);
     * 函数功能: 将点分十进制的字符串IP地址转换为网络字节序IP地址
    */
    ///////////////////////////////
    // 另一种写法
    addr.sin_addr.s_addr = inet_addr("192.168.241.139");
    socklen_t len = sizeof(struct sockaddr_in);
    int ret;
    ret = bind(sockfd, (struct sockaddr*)&addr, len);
    if (ret < 0)
    {
        perror("bind error\n");
        return -1;
    }

    /*
     * 函数名: ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
     *                          struct sockaddr *src_addr, socklen_t *addrlen);
     * 函数功能: 接收数据
     * 参数: sockfd:套接字描述符    buf:接收数据
     *       len:接收数据的长度     flags:默认赋0，阻塞接受(没数据就一直等待)
     *       src_addr:数据从哪里来,对端地址信息
     *       addrlen:地址信息长度(输入输出复合参数)
     * 返回值: 实际接收数据长度     失败:-1
    */
    while (1)
    {
        char buff[1024] = {0};
        struct sockaddr_in cli_addr;
        recvfrom(sockfd, buff, 1023, 0, (struct sockaddr*)&cli_addr, &len);
        printf("client say: %s\n", buff);
        memset(buff, 0x00, 1024);
        scanf("%s", buff);
        /*
         * 函数名: ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
         *                        const struct sockaddr *dest_addr, socklen_t addrlen);
         * 函数功能: 发送数据
         * 参数: dest_addr:目的端地址信息   addrlen:地址信息长度
        */

        sendto(sockfd, buff, strlen(buff), 0, (struct sockaddr*)&cli_addr, len);
    }
    close(sockfd);
    return 0;
}
