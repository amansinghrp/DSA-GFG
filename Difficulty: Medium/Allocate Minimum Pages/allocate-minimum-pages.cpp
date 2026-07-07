class Solution {
  public:
    
    //function similar to subaary sum equals k
    bool check(vector<int> arr, long long target, int k){
        long long cnt = 1;
        long long sum = 0;
        for(int num : arr){
            if(num > target) return false;
            if(sum + num <= target){
                sum += num;
            }
            else{
                cnt ++;
                sum = num;
            }
        }
        return cnt <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        long long n = arr.size();
        if(n < k) return -1;
        
        long long sum = 0;
        long long maxi = LLONG_MIN;
        for(long long num : arr){
            sum += num; 
            maxi = max(maxi, num);
        }
        
        long long low = maxi, high = sum, mid, ans;
        
        while(low <= high){
            mid = low + (high - low) / 2;            
            if(check(arr, mid, k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};