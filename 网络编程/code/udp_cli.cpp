/***********************************
 * 文件名称: udp_cli.cpp
 * 文件描述: 使用C++封装一个udp的socket类
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <error.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

class UdpSocket
{
    public:
        UdpSocket():m_sockfd(-1){}
    public:
        bool Socket()
        {
            m_sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
            if (m_sockfd < 0)
            {
                perror("socketr error");
                return false;
            }
            return true;
        }

        bool Bind(string &ip, uint16_t port)
        {
            sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port);
            addr.sin_addr.s_addr = inet_addr(ip.c_str());
            socklen_t len = sizeof(sockaddr_in);
            int ret = bind(m_sockfd, (sockaddr*)&addr, len);
            if (ret < 0)
            {
                perror("bind error");
                return false;
            }
            return true;
        }

        ssize_t Recv(char *buf, size_t len, sockaddr_in *addr = NULL)
        {
            int ret;
            sockaddr_in _addr;
            socklen_t addr_len = sizeof(sockaddr_in);
            ret = recvfrom(m_sockfd, buf, len, 0, (sockaddr*)&_addr, &addr_len);
            if (addr)
            {
                memcpy((void *)addr, (void*)&_addr, addr_len);
            }
            return ret;
        }

        ssize_t Send(const char *buf, size_t len, sockaddr_in *addr)
        {
            int ret;
            socklen_t addr_len = sizeof(sockaddr_in);
            ret = sendto(m_sockfd, buf, len, 0, (sockaddr*)addr, addr_len);
            return ret;
        }
        bool Close()
        {
            if (m_sockfd != -1)
            {
                close(m_sockfd);
                m_sockfd = -1;
            }
            return true;
        }
    private:
        int m_sockfd;
};

#define CHECK_RET(q) if (false == (q)){return -1;}
int main()
{
    UdpSocket sock;
    CHECK_RET(sock.Socket());
    sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9000);
    serv_addr.sin_addr.s_addr = inet_addr("192.168.241.139");
    while (1)
    {
        string str;
        cin >> str;
        sock.Send(str.c_str(), str.length(), &serv_addr);
        char buff[1024] = {0};
        sock.Recv(buff, 1024);
        printf("serve say: %s\n", buff);
    }
    sock.Close();
}
