// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
   static bool comp(vector<int>&v1, vector<int>&v2) {
        if(v1[1] == v2[1])
        return v1[2] < v2[2];
        
        return v1[1] < v2[1];
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int>>v(n, vector<int>(3));
        for(int i =0; i < n;i++)
        {
            v[i][0] = start[i];
            v[i][1] = end[i];
            v[i][2] = i;
        }
        // for(int i =0; i < n;i++)
        // {
        //     cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
        // }
        sort(v.begin(),v.end(), comp);
        int en = v[0][1];
        int count = 1;
        for(int i = 1; i < n; i++) {
            
            if(v[i][0] > en) {
                en = v[i][1];
                count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends