class Solution {
public:
    // Function to maximize the area of the square-shaped hole
    int maximizeSquareHoleArea(int n, int m, vector<int>& A, vector<int>& B) {
        int N = A.size(); // Number of elements in A vector
        int M = B.size(); // Number of elements in B vector
        
        // Sorting the vectors to identify consecutive elements
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int id = 0, mxh = 1, mxv = 1; // Initialization of variables
        
        // Loop through vector A to find the maximum horizontal consecutive count
        for(int i = 0; i < N; ++i) {
            int cnt = 1; // Counter for consecutive elements
            int j = i + 1;
            // Count consecutive elements in A
            while(i + 1 < N && A[i] + 1 == A[i + 1]) {
                ++i;
                ++cnt;
            }
            mxh = max(mxh, cnt); // Update maximum horizontal consecutive count
        }
        
        // Loop through vector B to find the maximum vertical consecutive count
        for(int i = 0; i < M; i++) {
            int cnt = 1; // Counter for consecutive elements
            // Count consecutive elements in B
            while(i + 1 < M && B[i] + 1 == B[i + 1]) {
                ++i;
                ++cnt;
            }
            mxv = max(mxv, cnt); // Update maximum vertical consecutive count
        }
        
        // Calculate the maximum possible area for the square hole
        int ans = (min(mxh, mxv) + 1) * (min(mxh, mxv) + 1);
        return ans; // Return the maximum area of the square-shaped hole
    }
};

