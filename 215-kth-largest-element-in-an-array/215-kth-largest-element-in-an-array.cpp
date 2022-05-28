class priorityQueue {
    public:
    int a[1000000];
    int size = 0;
    
    void heapify(int);
    void buildHeap(vector<int>&v, int k);
    int top() {
        return a[0];
    }
    
    void pop();
    void push(int element);
    
};
int parent(int i) { return (i-1)/2; }
void priorityQueue::pop() {
   a[0] = a[size-1];
        size--;
       heapify(0);
}
void priorityQueue::push(int element) {
    a[size] = element;
    size++;
    int i = size-1;
    while(i > 0 && a[(i-1)/2] > a[i])
    {
        swap(a[(i-1)/2], a[i]);
        i = (i-1)/2;
    }
}
 void priorityQueue::buildHeap(vector<int>&v, int k) {
        for(int i = 0; i < k; i++)
        {
            a[i] = v[i];
            size++;
        }
        for(int i = size-1; i >= 0; i --) {
            heapify(i);
        }
    }

void priorityQueue::heapify(int index) {
    int left = 2*index+1;
    int right = 2*index+2;
    int mini = index;
    if(left < size && a[left] < a[mini])
        mini = left;
    if(right < size && a[right] < a[mini])
        mini = right;
    if(mini != index)
    {
        swap(a[mini], a[index]);
        heapify( mini);
    }
}

class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
        priorityQueue pq;
        pq.buildHeap(nums, k);
        int i = k;
        for(; i < nums.size(); i++) {
            pq.push(nums[i]);
            
            if(pq.size > k)
                pq.pop();
        }
        return pq.top();
    }
};