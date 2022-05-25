class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue<pair<int, char>>pq;
    
        
        int count = 0;
        
        int freq[27] = {};
        for(char &ch : tasks)
            freq[ch-'A']++;
        
        for(int i = 0; i < 27; i++) {
            if(freq[i] > 0)
                pq.push({freq[i],('A'+i)});
        }
        
        while(!pq.empty()) {
                vector<pair<int, char>>v;
           int r = 0;
            while(!pq.empty() &&  r <= n) {
                if(pq.size() == 1) {
                    
                }
                pair<int, char>pr = pq.top();
                pq.pop();
                if(pr.first-1 > 0)
                v.push_back({pr.first-1, pr.second});
                count++;
                
                r++;
            }
            if(v.size() > 0)
            count += (n-r+1);
            
            for(auto it : v) {
                pq.push({it.first, it.second});
            }
         // cout<<count<<" ";            
            
        }
        return count;
    }
};