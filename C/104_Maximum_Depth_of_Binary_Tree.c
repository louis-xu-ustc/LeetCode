/**
    * File Name: 104_Maximum_Depth_of_Binary_Tree.c
    * Author: louis xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: Apr 4, 2016
*/

/**
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from
 * the root node down to the farthest leaf node.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	int left = maxDepth(root->left);
	int right = maxDepth(root->right);

	return (1 + ((left > right) ? left : right));
}
