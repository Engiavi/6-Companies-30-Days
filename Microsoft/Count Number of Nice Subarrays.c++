#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return lessequaltok(nums, k) - lessequaltok(nums, k - 1);
    }
private:
    int lessequaltok(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int l = 0, r = 0, ans = 0, n = nums.size(), sum = 0;
        while (r < n) {
            sum += nums[r]%2;
            while (sum > goal) {
                sum -= nums[l]%2;
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
};
// time and space complexity
// tc:- O(n)
// sc:- O(1)