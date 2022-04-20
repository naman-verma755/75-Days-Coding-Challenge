class Solution {
public:
    bool judgeSquareSum(int c) {
        
        map<long long,long long>squares;
        long long i = 1; 
        squares[0] = 1;
        while((i*i) <= c)
            squares[i*i++] = 1;
        
        for(auto it : squares) {
            
            if( squares.count(c-it.first)) 
                return true;
        }
        return false;
        
    }
};