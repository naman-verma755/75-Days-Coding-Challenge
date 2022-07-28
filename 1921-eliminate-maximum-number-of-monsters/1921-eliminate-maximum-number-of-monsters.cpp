class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        priority_queue<double, vector<double>, greater<double>>pq;
        
        for(int i = 0; i < dist.size(); i++) {
            pq.push(ceil((double)dist[i]/speed[i]));
        }
        int count = 0;
        int curr_time= 0;
        while(!pq.empty()) {
            if(pq.top() > curr_time)
                count++;
            else
                break;
            
            curr_time++;
            pq.pop();
        }
        return count;
    }
};