class MedianFinder {
public:
    priority_queue<int>pq1;
    priority_queue<int, vector<int>, greater<int>>pq2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        pq1.push(num);
        
        if((pq1.size()-pq2.size()) > 1) {
            pq2.push(pq1.top());
            pq1.pop();
        }
        
        if(pq1.size() > 0 && pq2.size() > 0 && pq1.top() > pq2.top())
        {
            int temp = pq1.top();
            pq1.pop();
            pq1.push(pq2.top());
            pq2.pop();
            pq2.push(temp);
        }
    }
    
    double findMedian() {
        
        if((pq1.size()+pq2.size())&1) {
            return (double)pq1.top();
        }
        else
        {
            double mean = pq1.top()+pq2.top();
            cout<<mean<<" ";
            return mean/2.0;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */