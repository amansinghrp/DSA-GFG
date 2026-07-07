class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n = a.size(), m = b.size();
        if(n > m ) return kthElement(b, a, k);
        
        /*
            binary search llimts
            0<=cut2<=m
            0 <= k - cut1 <= m
            k-m <= cut1 <= k
            thus BS limits are between [k-m and k]
        */
        
        int low, high, cut1, cut2;
        low = max(0, k-m);
        high = min(k, n);
        
        while(low <= high){
            cut1 = (low+high) >> 1;
            cut2 = k-cut1;
            
            int l1, l2, r1, r2;
            
            l1 = cut1 == 0 ? INT_MIN : a[cut1-1];
            l2 = cut2 == 0 ? INT_MIN : b[cut2-1];
            
            r1 = cut1 == n ? INT_MAX : a[cut1];
            r2 = cut2 == m ? INT_MAX : b[cut2];
            
            //if we found the exact halfs
            if(l1 <= r2 && l2 <= r1){
                return max(l1, l2);
            }
            else if(l1 > r2){
                high = cut1-1;
            }
            else{
                low = cut1+1;
            }
        }
        return -1;
    }
};