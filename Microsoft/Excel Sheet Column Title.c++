#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertToTitle(int colNum) {
        string res = "";
        while (colNum > 0) {
            int rem = (colNum - 1) % 26;
            char curr = 'A' + rem;
            res += curr;
            colNum = (colNum - 1) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Time and space complexity
// tc:- O(logn)
// sc:- O(1)