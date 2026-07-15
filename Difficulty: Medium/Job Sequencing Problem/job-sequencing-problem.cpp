class DSU{
    vector<int>par;
    public:
    
    DSU(int n ){
        par.resize(n+1);
        for(int i =0; i<=n; i++){
            par[i] = i;
        }
    }
    
    int findUPar(int u){
        if(par[u] == u){
            return u;
        }
        return par[u] = findUPar(par[u]);
    }
    
    void merge(int u, int v){
        par[v] = u;
    }
};

class Solution {
  private:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int, int>> jobs;
        int n = profit.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
            maxi = max(maxi, deadline[i]);
        }
        
        // sort the jobs based on profit
        // in descending order
        sort(jobs.begin(), jobs.end(), comp);
        
        // Find maximum deadline
        int d = INT_MIN;
        for(int i = 0; i<n; i++) {
            d = max(d, deadline[i]);
        }
       
        DSU ds(maxi);
        int cnt = 0, profitMax=0;
        
        for(int i =0; i<jobs.size(); i++){
            int dead = jobs[i].second;
            
            int slots = ds.findUPar(dead);
            
            if(slots != 0){
                profitMax += jobs[i].first;
                cnt++;
                ds.merge(ds.findUPar(slots-1), slots);
            }
        }
        
        return {cnt, profitMax};
    }
};