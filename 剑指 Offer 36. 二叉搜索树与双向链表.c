//剑指 Offer 36. 二叉搜索树与双向链表
//https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/solution/mian-shi-ti-36-er-cha-sou-suo-shu-yu-shuang-xian-5/
/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;

Node() {}

Node(int _val) {
val = _val;
left = NULL;
right = NULL;
}

Node(int _val, Node* _left, Node* _right) {
val = _val;
left = _left;
right = _right;
}
};
*/
class Solution {
public:
	Node *pre = NULL, *head = NULL;
	Node* treeToDoublyList(Node* root)
	{
		if (root == NULL)
			return NULL;
		dfs(root);
		head->left = pre;
		pre->right = head;
		return head;
	}
	void dfs(Node *cur)
	{
		if (cur == NULL)
			return;
		dfs(cur->left);
		if (pre != NULL)
			pre->right = cur;
		else
			head = cur;
		cur->left = pre;
		pre = cur;
		dfs(cur->right);
	}
};