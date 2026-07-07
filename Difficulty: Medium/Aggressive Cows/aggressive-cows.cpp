class Solution {
  private:
    bool check(vector<int> &arr, int minDist, int k){
        int cnt = 1, last = arr[0];
        for(int i =1; i<arr.size(); i++){
            int currDist = arr[i] - last;
            if(currDist >= minDist){
                cnt++;
                last = arr[i];
                if(cnt == k) return true;
            }
        }
        return false;
    }
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int low = 1, high = arr.back()-arr.front(), mid, ans;
        while(low <= high){
            mid = low + (high-low)/2;
            
            if(check(arr, mid, k)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};