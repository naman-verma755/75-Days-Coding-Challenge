class Solution {
public:
    
    
    int numDistinct(string s, string t) {
       
        int mod = 1000000007;
        int size1 = s.length();
        int size2 = t.length();
        vector<int>prev(size2+1,0);
        prev[0] = 1;
        vector<int>curr(size2+1,0);
        
        for(int i = 1; i <= size1; i++) {
            curr[0] = 1;
            for(int j = 1; j <= size2; j++) {
                int a = 0;
                if(s[i-1] == t[j-1]) {
                    a = prev[j-1];
                }
                int b = prev[j];
                curr[j] = (a+b)%mod;
            }
            prev = curr;
        }
        
        return prev[size2];
    }
};