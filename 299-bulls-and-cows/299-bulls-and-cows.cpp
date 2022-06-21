class Solution {
public:
    string getHint(string secret, string guess) {
        
        map<char, int>mp;
        int len = secret.length();
        int bulls = 0, cows = 0;
        for(int i = 0; i < len; i++) {
            if(secret[i] == guess[i]) {
                guess[i] = -1;
                bulls++;
            }
            else {
                mp[secret[i]]++;
            }
        }
        
        for(int i = 0; i < len; i++) {
            
            if(guess[i] != -1 && mp.count(guess[i]) && mp[guess[i]] > 0) {
                mp[guess[i]]--;
                cows++;
            }
        }
        
        return (to_string(bulls)+"A"+to_string(cows)+"B");
        
    }
};