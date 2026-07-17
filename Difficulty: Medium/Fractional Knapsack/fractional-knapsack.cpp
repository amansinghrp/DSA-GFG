class Solution {
  private:
    static bool comp(pair <int, int> &a, pair<int, int>&b){
        double rat1 = ((double)a.first) / a.second;
        double rat2 = ((double)b.first) / b.second;
        return rat1 > rat2;
    }
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int cap) {
        vector<pair<int, int>>store;
        int n = val.size();
        for(int i =0; i<n; i++){
            store.push_back({val[i], wt[i]});
        }
        sort(store.begin(), store.end(), comp);
        
        double ans =0;
        
        for(int i = 0; i<n; i++){
            int value = store[i].first;
            int weight = store[i].second;
            
            if(cap >= weight){
                ans += value;
                cap -= weight;
            }
            else{
                ans += ((1.0*value)/weight)*cap; //take portion
                cap = 0;
            }
        }
        return ans;
    }
};
