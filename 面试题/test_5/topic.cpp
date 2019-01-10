/*
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬
��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode *pNode = pHead;
        while (pNode != nullptr)
        {
            RandomListNode *pClo = new RandomListNode(0);
            pClo->label = pNode->label;
            pClo->next = pNode->next;
            pClo->random = nullptr;
            pNode->next = pClo;
            pNode = pClo->next;
        }
        
        pNode = pHead;
        while (pNode != nullptr)
        {
            RandomListNode *pClo = pNode->next;
            if (pNode->random != nullptr)
            {
                pClo->random = pNode->random->next;
            }
            pNode = pClo->next;
        }
        
        pNode = pHead;
        RandomListNode *pCloHead = nullptr;
        RandomListNode *pCloNode = nullptr;
        if (pNode != nullptr)
        {
            pCloHead = pCloNode = pNode->next;
            pNode->next = pCloNode->next;
            pNode = pNode->next;
        }
        while (pNode != nullptr)
        {
            pCloNode->next = pNode->next;
            pCloNode = pCloNode->next;
            pNode->next = pCloNode->next;
            pNode = pNode->next;
        }
        return pCloHead;
    }
};

/*
����һ��������ת��������������ı�ͷ��
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *pRHead = nullptr;
        ListNode *pNode = pHead;
        ListNode *pPrev = nullptr;
        
        while (pNode != nullptr)
        {
            ListNode *pNext = pNode->next;
            if (pNext == nullptr)
            {
                pRHead = pNode;
            }
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pRHead;
    }
};
/*
����һ����������������е�����k����㡣
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr || k == 0)
        {
            return nullptr;
        }
        ListNode *AHead = pListHead;
        ListNode *BHead = nullptr;
        
        for (int i = 0; i < k - 1; ++i)
        {
            if (AHead->next != nullptr)
            {
                AHead = AHead->next;
            }
            else
            {
                return nullptr;
            }
        }
        
        BHead  = pListHead;
        while (AHead->next != nullptr)
        {
            AHead = AHead->next;
            BHead = BHead->next;
        }
        return BHead;
    }
};