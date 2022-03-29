class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int countPairs = 0;
        map<int,int>mp;
        for(int i = 0; i < time.size(); i++) {
            
            int modulo = time[i] % 60;
            if(modulo == 0) {
                if(mp.count(0)) {
                    countPairs += mp[0];
                }
                
                mp[0] ++;
                continue;
            }
            if(mp.count(60-modulo))
            {
                countPairs += mp[60-modulo];
            }
            
            mp[modulo] ++;
            
        }
        
        return countPairs;
    
    }
};