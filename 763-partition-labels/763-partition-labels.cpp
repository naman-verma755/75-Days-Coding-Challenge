class Solution {
public:
    static bool cmp(pair<int, int>&pr1, pair<int, int>&pr2) {
        
        return pr1.first < pr2.second;
    }
    vector<int> partitionLabels(string s) {
        
         
        vector<pair<int, int>>v(27,{-1,-1});
        // for(int i = 0; i < 27; i++)
        //     v[i].first = v[i].second = i;
        
        map<char, pair<int, int>>mp;
        
        for(int i = 0; i < s.length(); i++) {
            
            if(v[s[i]-'a'].first == -1) {
               
                v[s[i]-'a'].first = i;
                v[s[i]-'a'].second = i;
            }
            else {
                v[s[i]-'a'].second = i;
            }
            
            
        }
        sort(v.begin(), v.end());
        vector<int>ans;
        int low = -1, high = -1;
        for(pair<int,int>&pr : v) {
            if(low == -1 && high == -1) {
                low = pr.first;
                high = pr.second;
            }
            else {
                if(pr.first <= high) {
                    low = min(low, pr.first);
                    high = max(high, pr.second);
                }
                else {
                    ans.push_back(high-low+1);
                    low = pr.first;
                    high = pr.second;
                }
            }
        }
        ans.push_back(high-low+1);
        
        return ans;
        
    }
};