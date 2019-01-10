/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
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
输入一个链表，反转链表后，输出新链表的表头。
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
输入一个链表，输出该链表中倒数第k个结点。
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