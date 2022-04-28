class Solution {
public:
    int func(int clip, int length, int n) {
        
        if(length == n)
            return 0;
        
        if(length > n)
            return INT_MAX;
        
        int a =  func(clip, length+clip, n);
        int b =  func(length, length+length, n);
        if( a == INT_MAX && b == INT_MAX)
            return a;
        if(a == INT_MAX && b != INT_MAX)
            return b+2;
        if(a != INT_MAX && b == INT_MAX)
            return a+1;
        
         
        return min(a+1,b+2);
    }
    int minSteps(int n) {
        if(n == 1)
            return 0;
        
        int count = func(1, 1, n)+1;
        return count;
    }
};