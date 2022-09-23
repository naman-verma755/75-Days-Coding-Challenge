class Priority_queue {
    public:
    int a[100001];
    int size;
    Priority_queue() {
        size =0;
    }
    int _size() {
        return size;
    }
    int top(){
        return a[0];
    }
    void heapify(int i) {
        long long left = 2*i+1;
        long long right = 2*i+2;
        int pos = i;
        if(left < size && a[left] < a[pos])
            pos = left;
        if(right < size && a[right] < a[pos])
            pos = right;
        
        swap(a[pos], a[i]);
        if(pos != i)
        heapify(pos);
    }
    void pop() {
        int ele = a[size-1];
        size--;
        a[0] = ele;
        heapify(0);
    }
    void push(int _val) {
        a[size] = _val;
        int i = size++;
        while(i > 0 && a[(i-1)/2] > a[i]){
            swap(a[(i-1)/2], a[i]);
            i =(i-1)/2;
        }
        
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // priority_queue<int, vector<int>, greater<int>>pq;
        Priority_queue pq;
        for(auto it : nums) {
            pq.push(it);
            
            if(pq._size() > k)
                pq.pop();
        }
        return pq.top();
    }
};