class Solution {
public:
    bool isValid(vector<int>& times){
        for(int i=0;i<times.size()-2;i++){
            if(times[i+2]-times[i] < 60)
                return true;
        }
        return false;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        unordered_map<string,vector<int>> umap;
        for(auto x: access_times){
            string hours = x[1].substr(0,2);
            string min = x[1].substr(2,2);
            int totalMin = stoi(hours)*60 + stoi(min);
            umap[x[0]].push_back(totalMin);
        }
        // for each employee 
        for(auto p:umap){
            if(p.second.size()<3){
                continue;
            }
            sort(p.second.begin(),p.second.end());
            // need to find three elements in an hour gap
            if(isValid(p.second)){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};