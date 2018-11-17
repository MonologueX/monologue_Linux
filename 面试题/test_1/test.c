/**
* Definition of singly-linked-list:
* class ListNode {
* public:
*     int val;
*     ListNode *next;
*     ListNode(int val) {
*        this->val = val;
*        this->next = NULL;
*     }
* }
*/

class Solution {
public:
	/**
	* @param head: the first node of linked list.
	* @return: An integer
	*/
	int countNodes(ListNode * head) {
		// write your code here
		int num = 1;
		if (NULL == head)
		{
			return 0;
		}
		for (; head->next != NULL; head = head->next)
		{
			num++;
		}
		return num;
	}
};