class Solution{
public:
vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        int i = 0;
        while(k>0){
            res.push_back(nums[i]);
            i++;
            k--;
        }
        for(int j=i;j<n;j++)
        {
            int mini_element = min_element(res.begin(), res.end()) - res.begin();
            if(res[mini_element] < nums[j]){
                res.push_back(nums[j]);
                res.erase(res.begin()+mini_element);
            }
        }
        return res;
    }
};
// time and space complexity
// time complexity: O(n)
// space complexity: O(1)