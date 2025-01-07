#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        queue<pair<pair<int, int>, int>> q; 
        int cntfr = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {  
                    vis[i][j] = 2; 
                    q.push({{i, j}, 0});  
                } 
                if (grid[i][j] == 1) {  
                    cntfr++;  
                }
            }
        }

        int tm = 0; 
        vector<int> delrow = {-1, 0, 1, 0};  
        vector<int> delcol = {0, 1, 0, -1};  
        int cnt = 0;  
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            tm = max(t, tm);  
            for (int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n &&
                    grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {
                    vis[nrow][ncol] = 2; 
                    q.push({{nrow, ncol}, t + 1});  
                    cnt++;  
                }
            }
        } 
        if (cnt != cntfr) return -1;
        return tm; 
    }
};

// time and space complexity
// tc:- O(m*n)
// sc:- O(m*n)