#include <iostream>
#include <assert.h>
#include <string.h>
#include <malloc.h>

using namespace std;

typedef char BTDataType;

typedef struct  BTNode 
{
    struct BTNode * m_left;
    struct BTNode * m_right;
    BTDataType m_data;
}BTNode;

///////////////////////////////////////////////
//  二叉树基本操作
///////////////////////////////////////////////

BTNode* BuyNode(BTDataType data)
{
    BTNode * pNewNode = (BTNode *)malloc(sizeof(BTNode));
    if (NULL == pNewNode)
    {
        assert(0);
        return nullptr;;
    }
    pNewNode->m_data = data;
    pNewNode->m_left = nullptr;
    pNewNode->m_right = nullptr;
    return pNewNode;
}

// 前序
void PreOrder(BTNode *pRoot)
{
    if (pRoot)
    {
        cout << pRoot->m_data << " ";
        PreOrder(pRoot->m_left);
        PreOrder(pRoot->m_right);
    }
}

// 中序
void InOrder(BTNode *pRoot)
{
    if (pRoot)
    {
        PreOrder(pRoot->m_left);
        cout << pRoot->m_data << " ";
        PreOrder(pRoot->m_right);
    }
}

// 后序
void PostOrder(BTNode *pRoot)
{
    if (pRoot)
    {
        PreOrder(pRoot->m_left);
        PreOrder(pRoot->m_right);
        cout << pRoot->m_data << " ";
    }
}

// 二叉树创建
void Create(BTNode **ppRoot, char *str, int size, int *index)
{
    assert(ppRoot);
    if ((*index) < size && '#' != str[*index])
    {
        *ppRoot = BuyNode(str[*index]);
        ++(*index);
        Create(&(*ppRoot)->m_left, str, size, index);
        ++(*index);
        Create(&(*ppRoot)->m_right, str, size, index);
    }
}

// 二叉树销毁
void DestoryBinTree(BTNode **ppRoot)
{
    assert(ppRoot);
    if (*ppRoot)
    {
        DestoryBinTree(&(*ppRoot)->m_left);
        DestoryBinTree(&(*ppRoot)->m_right);
        free(*ppRoot);
        *ppRoot = nullptr;
    }
}

// 二叉树拷贝
BTNode *CopyBinTree(const BTNode *pRoot)
{
    BTNode *pNewRoot = nullptr;
    if (pRoot)
    {
        pNewRoot = BuyNode(pRoot->m_data);
        if (pRoot->m_left)
        {
            pNewRoot->m_left = CopyBinTree(pRoot->m_left);
        }
        if (pRoot->m_right)
        {
            pNewRoot->m_right = CopyBinTree(pRoot->m_right);
        }
    }
    return pNewRoot;
}

// 获取节点个数
int GetSize(BTNode *pRoot)
{
    if (nullptr == pRoot)
    {
        return 0;
    }
    return GetSize(pRoot->m_left) + GetSize(pRoot->m_right) + 1;
}

// 叶子节点个数
int GetLeafSize(BTNode *pRoot)
{
    if (nullptr == pRoot)
    {
        return 0;
    }
    if (nullptr == pRoot->m_left && nullptr == pRoot->m_right)
    {
        return 1;
    }
    return GetLeafSize(pRoot->m_left) + GetLeafSize(pRoot->m_right);
}

// 第 k 层节点个数
int GetKSize(BTNode *pRoot, int k)
{
    if (nullptr == pRoot || k <= 0)
    {
        return 0;
    }
    if (1 == k)
    {
        return 1;
    }
    return GetKSize(pRoot->m_left, k - 1) + GetKSize(pRoot->m_right, k - 1);
}

// 二叉树高度
int GetHeight(BTNode *pRoot)
{
    if (nullptr == pRoot)
    {
        return 0;
    }
    int left = GetHeight(pRoot->m_left);
    int right = GetHeight(pRoot->m_right);
    return left > right ? left + 1 : right + 1;
}
///////////////////////////////////////////////
//  测试代码
///////////////////////////////////////////////
void Test1()
{
    char str[] = "ABD###CE##F";
    BTNode * pRoot = nullptr;
    BTNode *pCopyRoot = nullptr;
    int size = strlen(str);
    int index = 0;
    Create(&pRoot, str, size, &index);
    cout << "二叉树创建成功" << endl;
    cout << "前序：";
    PreOrder(pRoot);
    cout << endl;
    pCopyRoot = CopyBinTree(pRoot);
    cout << "二叉树拷贝成功" << endl;
    cout << "前序：";
    PreOrder(pCopyRoot);
    cout << endl;
    DestoryBinTree(&pCopyRoot);
    cout << "二叉树销毁成功" << endl;
    DestoryBinTree(&pRoot);
    cout << "二叉树销毁成功" << endl;
}

void Test()
{
    char str[] = "ABD###CE##F";
    BTNode * pRoot = nullptr;
    int size = strlen(str);
    int index = 0;
    Create(&pRoot, str, size, &index);
    int tree_size = GetSize(pRoot);
    cout << "二叉树节点个数：" << tree_size << endl;
    int tree_leaf_size = GetLeafSize(pRoot);
    cout << "二叉树节点个数：" << tree_leaf_size << endl;
    int tree_k_size = GetKSize(pRoot, 3);
    cout << "二叉树 3 层节点个数：" << tree_k_size << endl;
    int tree_height = GetHeight(pRoot);
    cout << "二叉树高度：" << tree_height << endl;
}

int main()
{
    Test();
    return 0;
}
