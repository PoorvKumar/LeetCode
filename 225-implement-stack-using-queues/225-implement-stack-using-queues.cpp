class MyStack 
{
private:
    queue<int> qA;
    queue<int> qB;
public:
    MyStack()
    {
        // top=-1;
        // qA.clear();
        // qB.clear();
    }
    
    void push(int x) 
    {
        qA.push(x);
    }
    
    int pop() 
    {
        int s=qA.size();
        
        if(s==0)
        {
            return -1;
        }
        
        s--;
        
        while(s--)
        {
            qB.push(qA.front());
            qA.pop();
        }
        
        int x=qA.front();
        qA.pop();
        
        qA.swap(qB);
        
        return x;
    }
    
    int top()
    {
        int s=qA.size();
        
        if(s==0)
        {
            return -1;
        }
        
        s--;
        
        while(s--)
        {
            qB.push(qA.front());
            qA.pop();
        }
        
        int x=qA.front();
        qA.pop();
        qB.push(x);
        
        qA.swap(qB);
        
        return x;
    }
    
    bool empty() 
    {
        return qA.empty();
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

