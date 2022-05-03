// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
        
//     }
// };
class Solution {
public:
   int heap_size = 0;
    // int capacity = ;
    int harr[1000000];
     int left(int i) { return (2*i + 1); }
  int parent(int i) { return (i-1)/2; }
    int right(int i) { return (2*i + 2); }
  
    void MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}
    int extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
  
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
  
    return root;
}
//     void deleteKey(int i)
// {
//     decreaseKey(i, INT_MIN);
//     extractMin();
// }
    
    void push(int k)
{
    // if (heap_size == capacity)
    // {
    //     cout << "\nOverflow: Could not insertKey\n";
    //     return;
    // }
  
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
  
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(harr[i], harr[parent(i)]);
       i = parent(i);
    }
}
    int findKthLargest(vector<int>& nums, int k) {
        vector<int>v;
        for(auto it : nums) {
            push(it);
            
            if(heap_size > k)
                int r = extractMin();
        }
        // for(int i = 0; i < heap_size; i++)
        //     cout<<harr[i]<<" ";
        return harr[0];
    }
};