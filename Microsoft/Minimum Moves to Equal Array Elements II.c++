class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            cnt += nums[r] - nums[l];
            l++;
            r--;
        }
        return cnt;
    }
};

// tc=O(nlogn)
// sc=O(1)