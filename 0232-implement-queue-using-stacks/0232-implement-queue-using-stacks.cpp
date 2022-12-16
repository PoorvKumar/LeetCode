class MyQueue 
{
private:
    stack<int> pri;
    stack<int> sec;
public:
    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        pri.push(x);
    }
    
    int pop() 
    {
        while(!pri.empty())
        {
            sec.push(pri.top());
            pri.pop();
        }
        
        int x=sec.top();
        sec.pop();
        
        while(!sec.empty())
        {
            pri.push(sec.top());
            sec.pop();
        }
        
        return x;
    }
    
    int peek() 
    {
        while(!pri.empty())
        {
            sec.push(pri.top());
            pri.pop();
        }
        
        int x=sec.top();
        // sec.pop();
        
        while(!sec.empty())
        {
            pri.push(sec.top());
            sec.pop();
        }
        
        return x;
    }
    
    bool empty() 
    {
        return pri.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */