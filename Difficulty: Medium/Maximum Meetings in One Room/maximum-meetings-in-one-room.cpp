class Solution {
  private:
    bool static comp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){
         if(a.second.second == b.second.second)
            return a.first < b.first;
        return a.second.second < b.second.second;
    }
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        vector<pair<int, pair<int ,int>>> intervals;
        int n = s.size();
        for(int i =0; i<n; i++){
            intervals.push_back({i+1, {s[i], f[i]}});
        }
        
        sort(intervals.begin(), intervals.end(), comp);
    
        vector<int> ans;
        int last = -1;
        for(auto &it : intervals){
            int ind = it.first;
            int start = it.second.first;
            int end = it.second.second;
            
            if(last == -1 || (start > last)){
                ans.push_back(ind);
                last = end;
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};