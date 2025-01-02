class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> image(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum = 0,cnt=0;
                for(int k=-1;k<=+1;k++){
                    for(int l=-1;l<=+1;l++){
                        int newR = i+k;
                        int newC = j+l;
                        if(newR >=0 && newR < m && newC >=0 && newC<n){
                            sum += img[newR][newC];
                            cnt++;
                        }
                    }
                }
                image[i][j] = sum / cnt;
            }
        }
        return image;
    }
};
// Time and space complexity
// tc:-o(m*n)
// sc:-o(1) as we don't consider the result array, if consider then it will be o(m*n)