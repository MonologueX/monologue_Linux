/*
*输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector <int> result;
        if (NULL == head)
            return result;
        stack<ListNode*> reverse;
        ListNode* node = head;
        while (NULL != node)
        {
            reverse.push(node);
            node = node->next;
        }
        while (!reverse.empty())
        {
            node = reverse.top();
            result.push_back(node->val);
            reverse.pop();
        }
        return result;
    }
};

/*
*请实现一个函数，将一个字符串中的每个空格替换成“%20”。
*例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (str == NULL && length <= 0)
            return;
        int originalLength = 0;
        int numberOfBlank = 0;
        int i = 0;
        while(str[i] != '\0')
        {
            ++originalLength;
            if(str[i] == ' ')
                ++numberOfBlank;
            ++i;
        }
        int newLength = originalLength + numberOfBlank * 2;
        if(newLength > length)
            return;
        int indexOfOriginal = originalLength;
        int indexOfNew = newLength;
        while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
        {
        if(str[indexOfOriginal] == ' ')
        {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        }
		else
        {
            str[indexOfNew --] = str[indexOfOriginal];
        }
        -- indexOfOriginal;
        }
    }
};