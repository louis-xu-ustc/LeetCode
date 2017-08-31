//
// Created by Yunpeng Xu on 8/31/17.
//

#ifndef C_TREENODE_H
#define C_TREENODE_H

#include "utils.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class MirrorTree {
private:
    TreeNode *newRoot;
    TreeNode *oldRoot;

public:
    MirrorTree () {}
    MirrorTree (TreeNode *root) : oldRoot(root) {}
    TreeNode* mirrorCopy(TreeNode *oldRoot);
    void testMirrorCopy();
    void traverse(TreeNode *root);
};

#endif //C_TREENODE_H
