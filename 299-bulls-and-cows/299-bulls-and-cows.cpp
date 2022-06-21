class Solution {
public:
    string getHint(string secret, string guess) {
        
        int mp1[10] = {};
        int mp2[10] = {};
    
        int len = secret.length();
        int bulls = 0, cows = 0;
        for(int i = 0; i < len; i++) {
            if(secret[i] == guess[i]) {
                guess[i] = -1;
                bulls++;
            }
            else {
                // cout<<secret[i]-'0'<<" ";
                bool flag1 = false, flag2 = false;
                if(mp2[secret[i]-'0'] > 0)
                    cows++,flag1 = true,mp2[secret[i]-'0']--;
                if(mp1[guess[i]-'0'] > 0)
                    cows++,flag2 = true,mp1[guess[i]-'0']--;
                if(!flag1)
                mp1[secret[i]-'0']++;
                if(!flag2)
                mp2[guess[i]-'0']++;
            }
        }
        
//         for(int i = 0; i < len; i++) {
            
//             if(guess[i] != -1 && mp.count(guess[i]) && mp[guess[i]] > 0) {
//                 mp[guess[i]]--;
//                 cows++;
//             }
//         }
        
        return (to_string(bulls)+"A"+to_string(cows)+"B");
        
    }
};