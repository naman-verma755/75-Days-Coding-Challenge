class TimeMap {
public:
    map<string, vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    
    void set(string key, string value, int timestamp) {
        // if(!mp.count(key))
        //     mp[key] = vector<pair<int,int>>();
        mp[key].push_back({timestamp, value});
        
    }
    
    string get(string key, int timestamp) {
        
        if(!mp.count(key))
            return "";
        
        int start = 0, end = mp[key].size()-1;
        string ans = "";
        while(start <= end) {
            int mid = (start+end)/2;
            if(timestamp >= mp[key][mid].first) {
                ans = mp[key][mid].second;
                start = mid+1;
            }
            else
                end = mid-1;
        }
        
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */