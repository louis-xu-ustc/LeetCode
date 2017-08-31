//
// Created by Yunpeng Xu on 8/31/17.
//

#include "TreeNode.h"

TreeNode*
MirrorTree::mirrorCopy(TreeNode *oldRoot) {
    if (oldRoot == NULL) {
        return NULL;
    }
    TreeNode *newRoot = new TreeNode(oldRoot->val);
    newRoot->left = mirrorCopy(oldRoot->right);
    newRoot->right = mirrorCopy(oldRoot->left);

    return newRoot;
}

void
MirrorTree::traverse(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << endl;
    traverse(root->left);
    traverse(root->right);
}

void
MirrorTree::testMirrorCopy() {
    TreeNode root(1), node1(2), node2(3), node3(4);
    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    oldRoot = &root;

    cout << "old Tree: " << endl;
    traverse(oldRoot);
    newRoot = mirrorCopy(&root);
    cout << "new Tree: " << endl;
    traverse(newRoot);
}