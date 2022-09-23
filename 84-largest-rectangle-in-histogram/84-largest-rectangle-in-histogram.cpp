class Stack {
    public:
    int a[100000];
    int size;
    
    Stack() {
        size = 0;
    }
    
    void push(int _val) {
        a[size++] = _val;
    }
    int top() {
        return a[size-1];
    }
    void pop() {
        size--;
    }
    bool empty(){
        if(size == 0)
            return true;
        return false;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        Stack st;
        int maxi = INT_MIN;
        int i=0;
        while(i < heights.size()){
            
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int k = st.top();
                st.pop();
                if(st.empty()) 
                    maxi = max(maxi, (heights[k]*i));
                else
                    maxi = max(maxi, (heights[k] * (i-st.top()-1)));
            }
            st.push(i++);
        }
        while(!st.empty() ) {
                int k = st.top();
                st.pop();
                if(st.empty()) 
                    maxi = max(maxi, (heights[k]*i));
                else
                    maxi = max(maxi, (heights[k] * (i-st.top()-1)));
            }
        return maxi;
    }
};