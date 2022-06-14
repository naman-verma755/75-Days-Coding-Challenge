class Solution {
public:
    static bool cmp(vector<int>&trip1, vector<int>&trip2) {
        return trip1[1] < trip2[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        sort(trips.begin(), trips.end(), cmp);
        map<int, int>mp;
        int carCapacity = 0;
        for(int i = 1; i <= trips.size(); i++) {
            
            // if(mp.count(i))
            //     carCapacity -= mp[i];
            // cout<<i<<" ";
            while(!pq.empty() && pq.top().first <= trips[i-1][1]) {
                carCapacity -= pq.top().second;
                pq.pop();
            }
            
            // mp[trips[i-1][2]] += trips[i-1][0];
            pq.push({trips[i-1][2], trips[i-1][0]});
            carCapacity += trips[i-1][0];
            
            if(carCapacity > capacity)
                return false;
        }
        return true;
    }
};