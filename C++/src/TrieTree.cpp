//
// Created by Yunpeng Xu on 8/30/17.
//

#include "TrieTree.h"


bool testTrieTree() {
    TrieTree tree;
    vector<string> descendants{
            "/Electronics/Computers/Graphics Cards",
            "/Electronics/Computers/Graphics Cards",
            "/Electronics/Computers/SSDs",
            "/Electronics/Computers/Graphics Cards",
            "/Electronics/Computers/SSDs",
            "/Electronics/TVs",
            "/Electronics/Computers/Graphics Cards",
            "/Electronics/TVs",
            "/Electronics/TVs",
            "/Garden",
            "/Automotive/Parts"
    };
    tree.buildTree(descendants);

    vector<string> testcases = {
            "/",
            "/Electronics",
            "/Electronics/Computers",
            "/Electronics/Computers/Graphics Cards",
            "/Electronics/TVs"
    };
    vector<int> results = {11, 9, 6, 4, 3};
    bool res = true;
    for (int i = 0; i < testcases.size(); i++) {
        int ans = tree.getCount(testcases[i]);
        //cout << "ans: " << ans << " expected: " << results[i] << endl;
        res = (ans - results[i] == 0);

        if (!res) break;
    }
    return res;
}
