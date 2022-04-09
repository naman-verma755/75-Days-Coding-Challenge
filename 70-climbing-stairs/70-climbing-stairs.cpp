class Solution {
public:
    int climbStairs(int n) {
                if(n <= 2)
            return n;
       
        int a = 1;
        int b = 2;
         
        
        for(int i = 3; i <= n; i++)
            {
            int c = a + b;
            swap(a,b);
            b = c;
        }
        
        return b;
    }
    
};