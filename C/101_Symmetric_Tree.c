/**
    * File Name: 101_Symmetric_Tree.c
    * Author: louis xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: Apr 3, 2016
*/

/**
 *  Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
	For example, this binary tree is symmetric:
		1
	   / \
	  2   2
	 / \ / \
	3  4 4  3
	But the following is not:
		1
	   / \
	  2   2
	   \   \
	   3    3
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 bool isSymmetricHelp(struct TreeNode *left, struct TreeNode *right) {
	if (!left && !right) return true;
	if (!left || !right) return false;
	if (left->val != right->val) {
		return false;
	}
	return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
 }

bool isSymmetric(struct TreeNode* root) {
	return !root || isSymmetricHelp(root->left, root->right);
}
