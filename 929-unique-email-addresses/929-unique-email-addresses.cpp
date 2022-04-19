class Solution {
public:
    void getEmail(string s, map<string, int>&mp) {
        
        string res = "";
        int i = 0;
        while( i < s.length()) {
        
            if(s[i] == '@') {
                res += s.substr(i, s.length());
                break;
            }
            if(s[i] == '.')
            {
                i++;
                continue;
            }
            if(s[i] == '+' )
            {
                i++;
                while(s[i] != '@')
                    i++;
                res += s.substr(i, s.length());
                break;
            }
            
            res += s[i];
            i++;
        }
        cout<<res<<" ";
        mp[res] = 1;
    }
    int numUniqueEmails(vector<string>& emails) {
        map<string, int>mp;
        for( auto it : emails) {
            
            getEmail(it, mp);
        }
        
        return mp.size();
        
    }
};