class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        map<char, int> start,end;
        for(int i = 0; i < s.length(); i++) {
            
            if(start.count(s[i])) {
                end[s[i]] = i;
            }
            else 
                start[s[i]] = end[s[i]] = i;
        }
        
        vector<pair<int,int>>v;
        
        for(auto it : start) {
            // cout<<it.first<<" "<<it.second<<" "<<end[it.first]<<endl;
            v.push_back({it.second,end[it.first]});
        }
        sort(v.begin(), v.end());
           vector<int>ans;
        int a = v[0].first, b = v[0].second;
        for(int i = 1; i < v.size(); i++) {
            if(b > v[i].first) {
                a = min(a,v[i].first);
                b = max(b,v[i].second);
            }
            else {
                ans.push_back((b-a+1));
                 a = v[i].first;
                
                b = v[i].second;
            }
        }
         ans.push_back((b-a+1));
     
        return ans;
        
    }
};