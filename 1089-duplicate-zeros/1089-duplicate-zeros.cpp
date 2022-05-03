class Solution {
public:
    int shift(int prev, int index, vector<int>& arr) {
          int in = -1;
        while(index < arr.size()) {
            
            int k = arr[index];
            arr[index] = prev;
            prev = k;
            if(in == -1 && arr[index] == 0)
                in = index;
            
            index++;
        }
        return in;
    }
    void duplicateZeros(vector<int>& arr) {
        
        for(int i = 0; i < arr.size()-1; ) {
            if(arr[i] == 0 ) {
                
              int r = shift(arr[i+1], i+2, arr);
                // cout<<r<<" ";
                arr[i+1] = 0;
                if(r == -1)
                    break;
                  
              
              i = r;
            }
            else
                i++;
        }
    }
};