class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        vector<pair<int,int>> events;

        for(int i = 0; i < n; i++) {
            events.push_back({arr[i], 1});
            events.push_back({dep[i], -1});
        }
        
        sort(events.begin(), events.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        int currentPlatforms = 0, maxPlatforms = 0;

        for(auto &e : events) {
            currentPlatforms += e.second;
            maxPlatforms = max(maxPlatforms, currentPlatforms);
        }

        return maxPlatforms;
    }
};
