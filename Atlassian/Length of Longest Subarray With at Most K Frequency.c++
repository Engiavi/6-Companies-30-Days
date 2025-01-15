class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
    int left = 0, right = 0, maxLength = 0;
    
    while (right < nums.size()) {
        count[nums[right]]++;
        
        while (count[nums[right]] > k) {
            count[nums[left]]--;
            if (count[nums[left]] == 0) {
                count.erase(nums[left]);
            }
            left++;
        }
        
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    
    return maxLength;
    }
};
// time ans space complexity
// tc: O(n),  
// sc: O(n), for the unordered_map