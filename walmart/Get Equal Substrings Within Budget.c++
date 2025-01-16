class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int n = s.size();
        int start = 0;
        int current_cost = 0;
        int max_length = 0;

        for (int end = 0; end < n; ++end) {
            current_cost += abs(s[end] - t[end]);

            while (current_cost > maxCost) {
                current_cost -= abs(s[start] - t[start]);
                ++start;
            }

            max_length = max(max_length, end - start + 1);
        }

        return max_length;
    }
};
// time complexity: O(n)
// space complexity: O(1)