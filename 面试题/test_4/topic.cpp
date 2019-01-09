/*
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��������
�ж��������Ƿ��и�������
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
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
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
����һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList��
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