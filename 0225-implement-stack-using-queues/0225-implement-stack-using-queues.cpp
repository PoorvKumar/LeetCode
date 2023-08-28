class MyStack 
{
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() 
    {
        // q1.clear();
        // q2.clear();
    }
    
    void push(int x) 
    {
        q1.push(x);
    }
    
    int pop() 
    {
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        int val=q1.front();
        q1.pop();
        
        q1.swap(q2);
        
        return val;
    }
    
    int top() 
    {
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        int val=q1.front();
        
        q2.push(q1.front());
        q1.pop();
        
        q1.swap(q2);
        
        return val;
    }
    
    bool empty() 
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */