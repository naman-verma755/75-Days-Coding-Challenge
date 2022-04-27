class Solution {
public:
    string minWindow(string s, string t) {
        
        map<char, int>mp1, mp2;
        int count = 0;
        for(char ch : t)
            mp1[ch]++;
        
        int left = 0, right = 0;
        int maxi = INT_MAX;
        string ans = "";
        while(right < s.length()) {
            
            mp2[s[right]] ++;
            // cout<<s[right]<<" "<<mp2[s[right]]<<endl;
            
            if(mp1.count(s[right]) && mp2[s[right]] <= mp1[s[right]])
                count++;
           
            if(count == t.length()) {
                // cout<<"Yes\n";
                // cout<<s[left]<<" "<<mp1[s[left]]<<" "<<mp2[s[left]]<<" "<<count<<endl;
            while(mp1[s[left]] < mp2[s[left]] || !mp1.count(s[left])) {
                // cout<<right<<" "<<s.substr(left, (right-left+1))<<"\n";
                
                if( mp1[s[left]] < mp2[s[left]])
                mp2[s[left]]--;
                left++;
            }
            int length = right-left+1;
            if(maxi > length) {
                    
                    maxi = length;
                    ans = s.substr(left, length);
                }
                
            }
            right++;
        }
        
        return ans;
    }
};