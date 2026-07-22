//User function template for C++

class Solution{   
private:
    bool solve(vector<int>arr, int ind, int sum, vector<vector<int>> &dp){
        if(sum == 0){
            return true;
        }
        if(ind == 0){
            return false;
        }
        if(dp[ind][sum] != -1){
            return dp[ind][sum];
        }
        bool notTake = solve(arr, ind-1, sum,dp);
        bool take = false;
        if(sum >= arr[ind-1]){
            take = solve(arr, ind-1, sum - arr[ind-1], dp);
        }
        return dp[ind][sum] = take||notTake;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        return solve(arr, n, sum, dp); 
    }
};
