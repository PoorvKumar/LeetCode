class MinStack 
{
private:
    stack<int> stk;
    // priority_queue<int,vector<int>,greater<int>> pq; //MIN HEAP
    multiset<int> mset;
public:
    MinStack() 
    {
        
    }
    
    void push(int val)
    {
        stk.push(val);
        // pq.push(val);
        mset.insert(val);
    }
    
    void pop() 
    {
        mset.erase(mset.find(stk.top()));
        stk.pop();
    }
    
    int top()
    {
        return stk.top();
    }
    
    int getMin() 
    {
        // return pq.top();
        return *mset.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */