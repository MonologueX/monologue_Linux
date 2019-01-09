/*
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数。
*/
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int rows = array.size();
		int cols = array[0].size();
		bool found = false;
		if (rows > 0 && cols > 0)
		{
			int row = 0;
			int col = cols - 1;
			while (row < rows && col >= 0)
			{
				if (array[row][col] == target)
				{
					found = true;
					break;
				}
				else if (array[row][col] > target)
					--col;
				else
					++row;
			}
		}
		return found;
	}
};

/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL && length <= 0)
			return;
		int Olength = 0;
		int Blength = 0;
		int i = 0;
		while (str[i] != '\0')
		{
			++Olength;
			if (str[i] == ' ')
				++Blength;
			++i;
		}
		int Nlength = Olength + 2 * Blength;
		if (Nlength > length)
			return;
		int Oindex = Olength;
		int Nindex = Nlength;
		while (Oindex >= 0 && Nindex > Oindex)
		{
			if (str[Oindex] == ' ')
			{
				str[Nindex--] = '0';
				str[Nindex--] = '2';
				str[Nindex--] = '%';
			}
			else
			{
				str[Nindex--] = str[Oindex];
			}
			--Oindex;
		}
	}
};
/*
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
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