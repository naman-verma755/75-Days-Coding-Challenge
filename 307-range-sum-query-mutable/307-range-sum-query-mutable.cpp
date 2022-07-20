class NumArray {
public:
    vector<int>v;
    int size;
    int seg[100000];
    
    int build(int index, int i, int n) {
        
        if(i == n)
        {
            seg[index] = v[i];
            return v[i];
        }
        int mid = (i+n)/2;
        
        int left = build((2*index+1), i, mid);
        int right = build((2*index+2), mid+1, n);
        seg[index] = left+right;
        return seg[index];
    }
    NumArray(vector<int>& nums) {
        v = nums;
        size = nums.size();
        int k = build(0, 0, size-1);
    }
    void updateVal(int index, int i, int n, int in, int val) {
        
        if(in < i || n < in)
            return;
        if(i == n) {
            if(in == i)
            seg[index] = v[in];
            
            return;
        }
        
        seg[index] += (v[in]-val);
        int mid = (i+n)/2;
        updateVal((2*index+1), i, mid, in, val);
        updateVal((2*index+2), mid+1, n, in, val);
        
    }
    void update(int index, int val) {
        
        int ele = v[index];
        v[index] = val;
        updateVal(0, 0, size-1, index, ele);
        // build(0, 0, size-1);
    }
    
    int get(int in, int i, int n, int l, int r) {
        
        if(n < l || r < i)
            return 0;
        
        // if(l == 0 && r == 3)
        // cout<<i<<" "<<n<<" ";
        // cout<<endl;
        // cout<<i<<" "<<n<<endl;
        if(l <= i && n <= r)
            return seg[in];
        // cout<<"after\n";
        //  if(l == 0 && r == 3)
        // cout<<i<<" "<<n<<" ";
        // cout<<endl;
        // if(l == 0 && r == 3)
        // cout<<"Yes"<<endl;
        int mid = (i+n)/2;
        
        int left = get((2*in+1), i, mid, l, r);
        int right = get((2*in+2), mid+1, n, l, r);
        // cout<<"=f "<<(2*in+1)<<" "<<left<<" "<<(2*in+2)<<" "<<right<<endl;
        return left+right;
    }
    void print(int in, int i, int n) {
        
        if(i == n) {
            // cout<<in<<" ="<<seg[in]<<" ";
            // cout<<endl;
            return;
        }
        // if(i > n)
        //     return;
        int mid = (i+n)/2;
        print((2*in+1), i, mid);
        print((2*in+2), mid+1, n);
        // cout<<in<<" ="<<seg[in]<<" ";
    }
    int sumRange(int left, int right) {
        
        // if(left == 0 && right == 3)
        // {
        //     print(0, 0, size-1);
        // }
        return get(0, 0, size-1, left, right);
        // return seg[0];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */