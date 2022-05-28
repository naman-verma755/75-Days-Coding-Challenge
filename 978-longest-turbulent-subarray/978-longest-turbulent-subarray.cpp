class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int maxi = 1;
        int size = a.size();
        if(size == 2)
        {
            if(a[0]  != a[1])
                return 2;
            else
                return 1;
        }
        
        for(int i = 1; i < size ; ) {
            
            if(a[i-1] > a[i]) {
                int counter = 1;
                int j = i;
                for( ; j < size; ) {
                    if(a[j-1] > a[j]) {
                        counter++;
                        j++;
                    }
                    else
                        break;
                    // cout<<"1"<<j<<endl;
                    if(j < size && a[j-1] < a[j])
                    {
                        counter++;
                        j++;
                    }
                    else
                        break;
                }
                maxi = max(maxi, counter);
                i = j;
            }
            else if(a[i-1] < a[i]) {
                int counter = 1;
                int j = i;
                for(; j < size; ) {
                    if(a[j-1] < a[j]) {
                        counter++;
                        j++;
                    }
                    else
                        break;
                    // cout<<"2"<<j<<endl;
                    if(j < size && a[j-1] > a[j])
                    {
                        counter++;
                        j++;
                    }
                    else
                        break;
                    
                }
                maxi = max(maxi, counter);
                i = j;
            }
            else
                i++;
            
            // cout<<i<<" ";
            
        }
        return maxi;
    }
};