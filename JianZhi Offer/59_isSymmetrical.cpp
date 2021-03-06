/*
 * 面试题59：对称的二叉树
 * 请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 */

#include <iostream>
#include <cstdlib>

using namespace std;

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (!pRoot)
			return true;

		return isSymmetrical(pRoot->left, pRoot->right);
	}

	bool isSymmetrical(TreeNode *pRoot1, TreeNode *pRoot2)
	{
		if (pRoot1 == NULL && pRoot2 == NULL)
			return true;
		else if (pRoot1 == NULL || pRoot2 == NULL)
			return false;
		else{
			if (pRoot1->val != pRoot2->val)
				return false;
			else{
				return isSymmetrical(pRoot1->left, pRoot2->right) && isSymmetrical(pRoot1->right, pRoot2->left);
			}
		}
		return true;
	}

};