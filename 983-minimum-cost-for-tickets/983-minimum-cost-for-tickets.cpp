class Solution {
public:
   int func(int day, set<int>&d, vector<int>&costs, vector<int>&dp) {
        
        if(day <= 0)
            return 0;
       if(dp[day] != -1)
           return dp[day];
        
        if(d.find(day) != d.end()) {
            
            int r1 = func(day-1,d, costs, dp)+costs[0];
            int r2 = func(day-7, d, costs, dp)+costs[1];
            int r3 = func(day-30, d, costs, dp)+costs[2];
            
            return dp[day] = min(r1, min(r2, r3));
        }
        else
            return dp[day] = func(day-1, d, costs, dp);
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        set<int>st;
        for(int day : days)
            st.insert(day);
        int maxDay = days[days.size()-1];
        vector<int>dp(maxDay+1, -1);
        return func(maxDay, st, costs, dp);
    }
};