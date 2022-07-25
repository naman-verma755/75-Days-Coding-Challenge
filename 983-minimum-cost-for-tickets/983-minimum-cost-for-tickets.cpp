class Solution {
public:
//     int func(int index, set<int>&st, vector<int>& costs, int destination) {
        
//         if(index > destination)
//             return 0;
        
//         if(st.find(index) != st.end()) {
            
//             int way1 = 0, way2 = 0, way3 = 0;
            
//             way1 = func(index+1, st, costs, destination)+costs[0];
//             way2 = func(index+7, st, costs, destination)+costs[1];
//             way3 = func(index+30, st, costs, destination)+costs[2];
        
//             return min(way1, min(way2, way3));
//         }
//         else
//             return func(index+1, st, costs, destination);
//     }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        set<int>st;
        int destination = 0;
        for(int day : days){
            st.insert(day); 
            destination = max(destination, day);
        }
       int dp[destination+1];
        dp[0] = 0;
        
        for(int i = 1; i <= destination; i++) {
            
            if(st.find(i) != st.end()) {
                int way1 = costs[0], way2 = costs[1], way3 = costs[2];
                
                way1 += dp[i-1];
                if(i-7 >= 0)
                    way2 += dp[i-7];
                if(i-30 >= 0)
                    way3 += dp[i-30];
                dp[i] = min(way1, min(way2, way3));
                
            }
            else
                dp[i] = dp[i-1];
        }
        return dp[destination];
    }
};