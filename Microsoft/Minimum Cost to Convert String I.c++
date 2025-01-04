class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        int n = source.length();
        vector<pair<int, int>> adj[26];
        for (int i = 0; i < original.size(); ++i) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            int z = cost[i];
            adj[x].push_back({y, z});
        }
        vector<vector<int>> dist(26, vector<int>(26, 1e9));
        for (int i = 0; i < 26; ++i) {
            dist[i][i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                pq;
            pq.push({0, i});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[i][u])
                    continue;

                for (auto [v, cost] : adj[u]) {
                    if (dist[i][u] != 1e9 && dist[i][u] + cost < dist[i][v]) {
                        dist[i][v] = dist[i][u] + cost;
                        pq.push({dist[i][v], v});
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = source[i] - 'a';
            int y = target[i] - 'a';

            if (x != y) {
                if (dist[x][y] == 1e9) {
                    return -1;
                }
                ans += dist[x][y];
            }
        }

        return ans;
    }
};

// time and space complexity
// tc=O(E+n)
// sc=O(E)