class FreqStack {
public:
    map<int, int>mp1;
    map<int, stack<int>>mp2;
    int count = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        // cout<<val<<" ";
        mp1[val]++;
        int k = mp1[val];
        if(k > count)
        {
            count++;
            mp2[count] = stack<int>();
        }
        
        mp2[k].push(val);
        
    }
    
    int pop() {
        int ele = mp2[count].top();
        mp1[ele] --;
        if(mp1[ele] == 0)
            mp1.erase(ele);
        // cout<<ele<<" ";
        mp2[count].pop();
        if(mp2[count].size() == 0)
        {
            mp2.erase(count);
            count--;
        }
        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */