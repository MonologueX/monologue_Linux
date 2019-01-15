/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        ListNode *preNode = nullptr;
        ListNode *node = pHead; 
        while (node != nullptr) 
        { 
            if (node->next != nullptr && node->val == node->next->val) 
            {
                int value = node->val;
                while (node->next != nullptr && node->next->val == value) 
                {
                    node = node->next;
                }
                if (preNode == nullptr) 
                {
                    pHead = node->next;
                } 
                else 
                {
                    preNode->next = node->next;
                }
            } 
            else 
            {
                preNode = node;
            }
            node = node->next;
        }
        return pHead;
    }
};
/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项
（从0开始，第0项为0）。n<=39
*/
class Solution {
public:
    int Fibonacci(int n) {
        int result[2] = {0, 1};
        if (n < 2)
            return result[n];
        int one = 1;
        int two = 0;
        int num = 0;
        for (int i = 2; i <= n; i++)
        {
            num = one + two;
            two = one;
            one = num;
        }
        return num;
    }
};
/*
在一个长度为n的数组里的所有数字都在0到n-1的范围内
数组中某些数字是重复的，但不知道有几个数字是重复的
也不知道每个数字重复几次。请找出数组中任意一个重复的数字
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
那么对应的输出是第一个重复的数字2。
*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (nullptr == numbers || length <= 0)
            return false;
        int i = 0;
        for (i < 0; i < length; i++)
        {
            if (numbers[i] < 0 || numbers[i] > length - 1)
                return false;
        }
        for (i = 0; i < length; i++)
        {
            while (numbers[i] != i)
            {
                if (numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }
        return false;
    }
};