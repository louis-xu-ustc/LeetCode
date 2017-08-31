//
// Created by Yunpeng Xu on 8/30/17.
//

#ifndef C_TRIETREE_H
#define C_TRIETREE_H

#include "utils.h"

class TrieNode {
public:
    int freq;
    unordered_map<string, TrieNode*> children;

    TrieNode () {
        freq = 1;
    }
    TrieNode (int freq) {
        this->freq = freq;
    }
};

class TrieTree {
public:
    TrieNode *root;
    TrieTree () {
        root = new TrieNode(0);
    }
    ~TrieTree() {
        delete root;
    }

    void buildTree(vector<string> &dict) {
        for (string s : dict) {
            stringstream ss(s);
            string item;
            TrieNode *curr = root;
            if (!s.empty()) {
                root->freq++;
            }
            while (getline(ss, item, '/')) {
                if (item.empty()) continue;
                if (curr->children.count(item) == 0) {
                    curr->children[item] = new TrieNode();
                    curr = curr->children[item];
                } else {
                    curr->children[item]->freq++;
                    curr = curr->children[item];
                }
            }
        }
    }

    int getCount(string s) {
        if (s.empty()) {
            return 0;
        }
        stringstream ss(s);
        string item;
        TrieNode *curr = root;
        int ans = 0;
        if (!s.empty()) {
            ans = curr->freq;
        }
        while (getline(ss, item, '/')) {
            if (item.empty()) continue;
            if (curr->children.count(item) == 0) {
                break;
            }
            ans = curr->children[item]->freq;
            curr = curr->children[item];
        }
        return ans;
    }
};

bool testTrieTree();

#endif //C_TRIETREE_H
