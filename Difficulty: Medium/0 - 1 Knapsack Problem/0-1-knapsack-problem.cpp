class Solution {
  public:
    int solve(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if(ind < 0){
            return 0;
        }
        
        if(dp[ind][W] != -1) return dp[ind][W];
        
        int notTake = solve(ind-1, W, val, wt, dp);
        int take = 0;
        if(W >= wt[ind]){
            take = val[ind] + solve(ind-1, W-wt[ind], val, wt, dp);
        }
        return dp[ind][W] = max(take, notTake);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<vector<int>>dp(n, vector<int>(W+1, -1));
        return solve(n-1, W, val, wt, dp);
    }
};