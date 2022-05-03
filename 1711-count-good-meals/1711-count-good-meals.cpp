class Solution {
public:
    long long mod = 1000000007;
    int bin(vector<long long>&a, int key) {
        
        int ans = 0;
        
        int start = 0, end = a.size()-1; 
        while(start <= end) {
            int mid = (start+end)/2;
            if(a[mid] >= key) {
                ans = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return ans;
    }
    void func(vector<long long>&mp, int maxi) {
        
        for(long long i = 1; i <= maxi; i = i*2) {
            mp.push_back(i);
        }
    }
    int countPairs(vector<int>&a) {
        int size = a.size();
        // sort(a.begin(), a.end());
        if(size == 1)
            return 0;
        int maxi1 = INT_MIN, maxi2 = INT_MIN;
        
        for(int meal : a) {
            if(meal > maxi1) {
                maxi2 = maxi1;
                maxi1 = meal;
            }
            else if(meal > maxi2)
                maxi2 = meal;
        }
        // cout<<maxi1<<maxi2<<" ";
        vector<long long>g;
        func(g, (maxi1+maxi2));
        map<long long, long long>mp;
        // mp[a[0]]++;
        long long count = 0;
        // for(auto it : g)
        //     cout<<it<<" ";
        for(int i = 0; i < size; i++) {
             int j = bin(g, a[i]);
            // cout<<j<<" ";
             for(; j < g.size(); j++ ) {
                if(mp.count(g[j]-a[i])) {
                    count = (count%mod+mp[g[j]-a[i]]%mod)%mod;
                }
                
            }
//             for(long long k : g) {
//                 if(mp.count(k-a[i])) {
//                     count = (count%mod+mp[k-a[i]]%mod)%mod;
//                 }
                
//             }
            mp[a[i]]++;
            
        }
        
        
        
        return count;
    }
};