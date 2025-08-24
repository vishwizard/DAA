

class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        vector<vector<int>> ans;
        for(int &a : arr) mp[a]++;
        
        for(auto &[key,val] : mp){
            ans.push_back({key,val});
        }
        return ans;
    }
};