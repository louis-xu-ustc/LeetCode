/**
 * Given a binary tree, return the bottom-up level order traversal of its nodes' 
   values. (ie, from left to right, level by level from leaf to root).

	For example:
	Given binary tree [3,9,20,null,null,15,7],
	    3
	   / \
	  9  20
	    /  \
	   15   7
	return its bottom-up level order traversal as:
	[
	  [15,7],
	  [9,20],
	  [3]
	]
 */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import
public class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> container = new ArrayList<List<Integer>>();
        if (root == null) return container;
        TreeNode cur = null;
        Queue<TreeNode> sameLevel = new LinkedList<TreeNode>();
        sameLevel.add(root);
        while (!sameLevel.isEmpty()) {
            List<Integer> oneLevel = new ArrayList<Integer>();
            Queue<TreeNode> temp = new LinkedList<TreeNode>();
            while(!sameLevel.isEmpty()) {
                cur = sameLevel.remove();
                oneLevel.add(cur.val);
                if (cur.left != null)  temp.add(cur.left); 
                if (cur.right != null) temp.add(cur.right);
            }
            container.add(0, oneLevel);
            sameLevel = temp;
        }
        return container;
    }
}