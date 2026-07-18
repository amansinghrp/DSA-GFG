class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        int m = pat.size();
        int n = txt.size();
        int q = 101;//modulo value to avoid overflow
        vector<int>ans;
        int patHash = 0;
        int txtHash = 0;
        int d=31; //Number of characters in the input alphabet (ASCII) --> taking 31 as all are lower case alphabets in input
        
        int h = 1;//higher order digit multiplier
        //precompute pow(d, m-1)%q
        for(int i =0; i<m-1; i++){
            h = (h*d)%q;
        }
        
        //compute hash value of patter and the first window of source string of the same lenght as pattern
        for(int i =0; i<m; i++){
            patHash = (d*patHash + pat[i])%q;
            txtHash = (d*txtHash + txt[i])%q;
        }
        
        for(int i =0; i<= n-m; i++){
            if(patHash == txtHash){
                if(txt.substr(i, m) == pat){
                    ans.push_back(i);
                }
            }
            
            if(i < n-m){
                txtHash = (d*(txtHash-txt[i]*h) + txt[i+m])%q;
                if(txtHash < 0){
                    txtHash += q;
                }
            }
        }
        
        return ans;
    }
};