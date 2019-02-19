//#include "Compress.h"
//#include "Huffman.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define READ_MAXSIZE 1024
int m_informations[256] = {0};

int compress(const std::string& compress_name)
{
    //typedef HuffmanNode<CharInformation>* Node;
    ///////////////////////////////////////////////
    //  1.获取源字符出现次数
    ///////////////////////////////////////////////
    FILE *fin = fopen(compress_name.c_str(), "rb");
    if (NULL == fin)
    {
        std::cout << "打开文件失败" << std::endl;
        return -1;
    }
    std::cout << "打开文件成功" << std::endl;

    char ReadBUff[READ_MAXSIZE];
    size_t SourceCount = 0;
    while (1)
    {
        size_t ReadSize = fread(ReadBUff, 1, 1024, fin);
        if (0 == ReadSize)
        {
            std::cout << "读取文件失败" << std::endl;
            return -1;
        }
        std::cout << "读取成功：[ReadSize] = " << ReadSize << std::endl;

        for (size_t i = 0; i < ReadSize; i++)
        {
            //m_informations[(unsigned char)ReadBUff[i]].m_count++;
            m_informations[ReadBUff[i]]++;
            SourceCount++;
        }
    }
    std::cout << "源文件出现字符总数" << std::endl;
    ///////////////////////////////////////////////
    //  2.创建哈夫曼树
    ///////////////////////////////////////////////

    //////////////////////////////////////////////
    //  3.根据Huffman树来获取Huffman编码
    ///////////////////////////////////////////////
    
    ///////////////////////////////////////////////
    //  4.
    ///////////////////////////////////////////////
}

int main()
{
    compress("1.txt");
}
