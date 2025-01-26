class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                       vector<vector<int>>& queries) {
        vector<int> result;
        int n = nums.size();
        for (vector<int> x : queries) {
            priority_queue<pair<string, int>> pq;
            for (int i = 0; i < n; i++) {
                int t = nums[i].length() - x[1];
                string p = nums[i].substr(t, x[1]);
                if (pq.size() < x[0])
                    pq.push({p, i});
                else {
                    if (pq.top().first > p) {
                        pq.pop();
                        pq.push({p, i});
                    }
                }
            }
            int val = pq.top().second;
            result.push_back(val);
        }
        return result;
    }
};