/*
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
�ظ��Ľ�㲻��������������ͷָ�롣 
���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
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
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n��
����0��ʼ����0��Ϊ0����n<=39
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
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ��
������ĳЩ�������ظ��ģ�����֪���м����������ظ���
Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ�������
���磬������볤��Ϊ7������{2,3,1,0,2,5,3}��
��ô��Ӧ������ǵ�һ���ظ�������2��
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