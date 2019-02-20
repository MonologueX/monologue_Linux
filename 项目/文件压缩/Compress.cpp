#define _CRT_SECURE_NO_WARNINGS

#include "Compress.h"
#include <iostream>
#include <assert.h>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;

#define READ_MAXSIZE 1024

std::string Compress::GetFileExtensio(const std::string& CompressName)
{
	size_t pos = CompressName.find_last_of('.');
	return CompressName.substr(pos);
}

std::string Compress::GetFilepath(const std::string& CompressName)
{
	size_t pos = CompressName.find_last_of('.');
	return CompressName.substr(0, pos);
}

int Compress::GetHuffmanCode(Node root)
{
	if (nullptr == root)
	{
		return -1;
	}
	Node cur = root;
	Node Parent = cur->m_parent;
	std::string& code = m_informations[(unsigned char)cur->m_weight.m_ch].m_code;
	while (Parent)
	{
		if (Parent->m_left == cur)
		{
			code += '0';
		}
		else
		{
			code += '1';
		}
		cur = Parent;
		Parent = cur->m_parent;
	}
	reverse(code.begin(), code.end());
	GetHuffmanCode(root->m_left);
	GetHuffmanCode(root->m_right);
	return 0;
}

int Compress::compress(const std::string& CompressName)
{
	///////////////////////////////////////////////
	//  1.获取源字符出现次数
	///////////////////////////////////////////////
	FILE *fin = fopen(CompressName.c_str(), "rb");
	if (NULL == fin)
	{
		std::cout << "打开文件失败" << std::endl;
		return -1;
	}
	std::cout << "打开文件成功" << std::endl;

	char ReadBuff[READ_MAXSIZE];
	size_t SourceCount = 0;
	while (1)
	{
		size_t ReadSize = fread(ReadBuff, 1, 1024, fin);
		if (0 == ReadSize)
		{
			std::cout << "读取完毕" << std::endl;
			break;
		}
		std::cout << "读取成功：[ReadSize] = " << ReadSize << std::endl;

		for (size_t i = 0; i < ReadSize; i++)
		{
			m_informations[(unsigned char)ReadBuff[i]].m_count++;
			std::cout << m_informations[(unsigned char)ReadBuff[i]].m_count << " ";
			SourceCount++;
		}
	}
	//std::cout << "源文件出现字符总数" << SourceCount << std::endl;
	for (size_t i = 0; i < 256 && m_informations[(unsigned char)ReadBuff[i]].m_count != 0; i++)
		std::cout << m_informations[i].m_count << " ";
	std::cout << std::endl;
	///////////////////////////////////////////////
	//  2.创建哈夫曼树
	///////////////////////////////////////////////

	HuffmanTree<CharInformation> hf((m_informations));

	//////////////////////////////////////////////
	//  3.根据Huffman树来获取Huffman编码
	///////////////////////////////////////////////
	GetHuffmanCode(hf.GetRoot());

	///////////////////////////////////////////////
	//  4.用每个字符的编码改写源文件
	///////////////////////////////////////////////
	Head head;
	head.FileExtension = GetFileExtensio(CompressName);
	for (size_t i = 0; i < 256 && m_informations[i].m_count != 0; i++)
	{
		head.Code += m_informations[i].m_ch;//保存字符
		head.Code += ':';
		// itoa((int)m_informations[i].m_count, head.StrCount, 10);
		// Windows 可以用 itoa
		sprintf(head.StrCount, "%d", (int)m_informations[i].m_count);
		head.Code += head.StrCount;
		head.Code += '\n';
		head.LineCount++;
	}
	std::string HeadInformation;
	HeadInformation += head.FileExtension;
	HeadInformation += '\n';
	//itoa(head.LineCount, head.StrCount, 10);
	sprintf(head.StrCount, "%d", (int)head.LineCount);
	HeadInformation += head.StrCount;
	HeadInformation += '\n';
	HeadInformation += head.Code;
	string  compressfile = GetFilepath(CompressName);//获取文件前缀
	compressfile += ".ggzip";//然后在前缀后面加上压缩之后的后缀
	FILE* fout = fopen(compressfile.c_str(), "wb");
	assert(fout);
	std::cout << "压缩名已经获取" << std::endl;
	char *WriteBuff = new char[READ_MAXSIZE];
	char pos = 0;
	char ptr = 0;
	size_t WriteSize = 0;
	fseek(fin, 0, SEEK_SET);

	int CompreeCount = 0;

	while (true)
	{
		size_t readsize = fread(ReadBuff, 1, READ_MAXSIZE, fin);
		if (0 == readsize)
		{
			break;
		}
		for (size_t i = 0; i < readsize; ++i)
		{
			string& code = m_informations[(unsigned char)ReadBuff[i]].m_code;
			for (size_t j = 0; j < code.size(); ++j)
			{
				pos++;
				if ('1' == code[j])
				{
					ptr |= 1;
				}
				else
				{
					ptr |= 0;
				}
				if (pos == 8)
				{
					WriteBuff[WriteSize++] = ptr;
					ptr = 0;
					if (READ_MAXSIZE == WriteSize)
					{
						fwrite(WriteBuff, 1, READ_MAXSIZE, fout);
						WriteSize = 0;
					}
					CompreeCount++;
					pos = 0;
				}
				ptr <<= 1;
			}
		}
	}
	//如果没满8个比特位
	if (pos < 8)
	{
		WriteBuff[WriteSize++] = (ptr << (8 - pos));
		CompreeCount++;
	}
	fwrite(WriteBuff, 1, WriteSize, fout);
	fclose(fin);
	fclose(fout);
	cout << "压缩了的字符个数：" << CompreeCount << endl;
	delete[] ReadBuff;
	delete[] WriteBuff;
}

int main()
{
	Compress c;
	c.compress("1.txt");
	return 0;
}