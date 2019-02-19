#define __HUFFMAN_H__ 
#ifdef __HUFFMAN_H__
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
template<class W>
struct HuffmanNode
{
    HuffmanNode(W *weight)
        :m_left(NULL)
        ,m_right(NULL)
        ,m_parent(NULL)
        ,m_weight(weight)
    {}
    HuffmanNode *m_left;
    HuffmanNode *m_right;
    HuffmanNode *m_parent;
    W *m_weight;
};

template<class W>
class HuffmanTree
{
    typedef HuffmanNode<W> Node;
    typedef HuffmanNode<W> *PNode;
    struct cmp 
    {
        bool operator()(W &left,W& right)
        {
            return left>right;
        }
    };
    public:
        HuffmanTree()
            :m_root(NULL)
        {}
        int CreateHuffmanTree(std::vector<W> array)
        {
            std::priority_queue<W,std::vector<W>,cmp> q;
            for (size_t i = 0; i < 256 && array[i] != '\0'; i++)
            {
                PNode node = new Node;
                q.push(node);
            }
            if (q.size() == 0)
            {
                std::cout << "数组为空" << std::endl;
                m_root = NULL;
                return -1;
            }
            while (q.size() > 1)
            {
                PNode pRight = q.top();
                q.pop();
                PNode pLeft = q.top();
                q.pop();

                PNode pParent = new Node(pRight->m_weight + pLeft->m_weight);
                pParent->m_left = pLeft;
                pLeft->m_parent = pParent;
                pParent->m_right = pRight;
                pRight->m_parent = pParent;
                q.push(pParent);
            }
            m_root = q.top();
            std::cout << "哈夫曼树创建成功" << std::endl;
            return 1;
        }
        int DestoryHuffmanTree(PNode &pRoot)
        {
            while (pRoot)
            {
                DestoryHuffmanTree(pRoot->m_left);
                DestoryHuffmanTree(pRoot->m_right);
                delete pRoot;
                pRoot = NULL;
            }
        }
    private:
        PNode m_root;
};

#endif
