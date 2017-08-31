#include <iostream>

#include "src/TrieTree.h"
#include "src/BinPacking.h"
#include "src/TreeNode.h"
#include "src/multiThread.h"

int main() {

    // TrieTree
    if (!testTrieTree()) {
        cout << "test Trie Tree case failed!" << endl;
    } else {
        cout << "test Trie Tree case passed!" << endl;
    }

    if (!testBinPacking()) {
        cout << "test Pin Packing case failed!" << endl;
    } else {
        cout << "test Pin Packing case passed!" << endl;
    }

    MirrorTree *mirrorTree = new MirrorTree();
    mirrorTree->testMirrorCopy();

    return 0;
}