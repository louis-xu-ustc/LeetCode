//
// Created by Yunpeng Xu on 8/30/17.
//

#include "BinPacking.h"

bool testBinPacking() {
    vector<vector<int>> tasksList = {
            {2, 5, 4, 7, 1, 3, 8},
            {4, 8, 1, 4, 2, 1},
            {9, 8, 2, 2, 5, 4},
    };
    vector<int> expected = {
            3, 2, 4
    };
    BinPacking binPacking(10);

    int i = 0;
    for (vector<int> &tasks : tasksList) {
        int ans = binPacking.firstFitDecreasing(tasks);
        if (ans != expected[i]) {
            cout << "failed for case: " << i << " ans: " << ans << " expected: " << expected[i] <<endl;
            return false;
        }
        i++;
    }
    return true;
}