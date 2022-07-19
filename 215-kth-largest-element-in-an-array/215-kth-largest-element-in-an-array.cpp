class pqueue{
    public:
    int *a;
    int size = 0;
    pqueue(int n) {
        a = (int*)malloc((n+1)*sizeof(int));
    }
    void push(int key);
    void maxHeapify( int index);
    int top();
    void pop();
    void print() {
        for(int j = 0; j < size; j++)
            cout<<a[j]<<" ";
        cout<<endl;
    }
};

void pqueue::push(int element) {
    int index = size++;
    a[index] = element;
    int parent = (index-1)/2;
    while(index > 0 && a[parent] > a[index]) {
        swap(a[parent], a[index]);
        index = parent;
        parent = (index-1)/2;
    }
}
void pqueue::maxHeapify( int index) {
  
    int left = (2*index+1);
    int right = (2*index+2);
    int largest = index;
    if(left < size && a[left] < a[largest]) 
        largest = left;
    if(right < size && a[right] < a[largest])
        largest = right;
    
    if(largest != index) {
        swap(a[index], a[largest]);
        maxHeapify(largest);
    }
}

void pqueue::pop() {
   
    a[0] = a[size-1];
    size--;
    maxHeapify(0);
}
int pqueue::top() {
  return a[0];
}


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
       pqueue *pq = new pqueue(k);
        for(int  i = 0; i < n; i++) {
            pq->push(nums[i]);
            // pq->print();
            if(pq->size > k)
                pq->pop();
            
        }
     return pq->top();   
    }
    
};