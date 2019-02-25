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

void PreOrder(BTNode *pRoot)
{
    if (pRoot)
    {
        printf("%c", pRoot->m_data);
        PreOrder(pRoot->m_left);
        PreOrder(pRoot->m_right);
    }
}

void InOrder(BTNode *pRoot)
{
    if (pRoot)
    {
        PreOrder(pRoot->m_left);
        printf("%c", pRoot->m_data);
        PreOrder(pRoot->m_right);
    }
}

void PostOrder(BTNode *pRoot)
{
    if (pRoot)
    {
        PreOrder(pRoot->m_left);
        PreOrder(pRoot->m_right);
        printf("%c", pRoot->m_data);
    }
}

void Create(BTNode **pRoot, char *str, int size, int *index)
{
    assert(pRoot);
    if ((*index) < size && '#' != str[*index])
    {
        *pRoot = BuyNode(str[*index]);
        ++(*index);
        Create(&(*pRoot)->m_left, str, size, index);
        ++(*index);
        Create(&(*pRoot)->m_right, str, size, index);
    }
}

void Test()
{
    char *str = "ABD###CE##F";
    BTNode * pRoot = nullptr;
    int size = strlen(str);
    int index = 0;
    Create(&pRoot, str, size, &index);
    PreOrder(pRoot);
}

int main()
{
    Test();
    return 0;
}
