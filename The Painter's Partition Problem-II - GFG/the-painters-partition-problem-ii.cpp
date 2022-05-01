// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossible(long long maxWork, int arr[], int n, int k ) {
        
        int people=1;
        
        int work =0;
        // cout<<"N="<<n<<endl;
        for(int i = 0; i < n; i++) {
            if(arr[i] > maxWork)
            return false;
            if((work+arr[i]) > maxWork) {
                people++;
                work = arr[i];
            }
            else
            work+= arr[i];
            
            // if(people > k)
            // return false;
        }
        // cout<<maxWork<<" "<<people<<" "<<k<<endl;
        if(people <= k)
        return true;
        return false;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        long long sum = 0;
        for(int i = 0; i < n; i++)
        sum += arr[i];
        
        long long start = 1, end = sum;
        long long ans = 0;
        while(start <= end) {
            long long mid = (start+end)/2;
            
            if(isPossible(mid, arr, n, k)) {
                // cout<<"yes";
                ans = mid;
                end = mid-1;
            }
            else
            start = mid+1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends