// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    stack<char>st;
    int i = 0;
    while(i < s.length()) {
        
        if(st.empty())
        {
            st.push(s[i]);
            i++;
            continue;
        }
        
        if(st.top() == '{' && s[i] == '}') {
            
            st.pop();
            
        }
        else
        st.push(s[i]);
        
        i++;
    }
    if(st.size()&1)
    return -1;
    int count = 0;
    while(!st.empty()) {
        char ch1 = st.top();
        st.pop();
        char ch2 = st.top();
        st.pop();
        if(ch2 == '{' && ch1 == '}')
        continue;
        else if(ch2 == '}' && ch1 == '{') {
            count += 2;
        }
        else
        count += 1;
        
        
    }
    
    return count;
}









