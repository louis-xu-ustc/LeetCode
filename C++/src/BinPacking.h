//
// Created by Yunpeng Xu on 8/30/17.
//

#ifndef C_BINPACKING_H
#define C_BINPACKING_H

#include "utils.h"

class BinPacking {
private:
    int capacity;

public:
    BinPacking(int cap) {
        capacity = cap;
    }

    int firstFitDecreasing(vector<int> &tasks) {
        int n = tasks.size();
        if (n == 0) return 0;
        sort(tasks.begin(), tasks.end(), greater<int>());

        int ans = 0;
        vector<int> bin_remain(n, capacity);

        for (int i = 0; i < n; i++) {
            int j;
            for (j = 0; j < ans; j++) {
                if (bin_remain[j] >= tasks[i]) {
                    bin_remain[j] -= tasks[i];
                    break;
                }
            }
            if (j == ans) {
                bin_remain[ans] -= tasks[i];
                ans++;
            }
        }
        if (bin_remain[ans] != capacity) ans += 1;
        return ans;
    }
};

bool testBinPacking();


#endif //C_BINPACKING_H
