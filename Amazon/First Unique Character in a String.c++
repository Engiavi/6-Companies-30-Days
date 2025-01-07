#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>calElementFreq(26);
        for(auto it:s){
            calElementFreq[it-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(calElementFreq[s[i]-'a']==1) return i;
        }
        return -1;
    }
};

// Time Complexity:- O(n)
// Space Complexity:- O(1)