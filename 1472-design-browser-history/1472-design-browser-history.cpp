class BrowserHistory 
{
private:
    deque<string> prev;
    string curr;
    deque<string> next;
public:
    BrowserHistory(string homepage)
    {
        curr=homepage;
        prev.clear();
        next.clear();
        return ;
    }
    
    void visit(string url)
    {
        prev.push_back(curr);
        curr=url;
        next.clear();
        return ;
    }
    
    string back(int steps)
    {
        if(prev.empty())
        {
            return curr;
        }
        
        next.push_front(curr);
        steps--;
        
        while(steps-- && prev.size()>1)
        {
            next.push_front(prev.back());
            prev.pop_back();
        }
        
        curr=prev.back();
        prev.pop_back();
        
        return curr;
    }
    
    string forward(int steps)
    {
        if(next.empty())
        {
            return curr;
        }
        
        prev.push_back(curr);
        steps--;
        
        while(steps-- && next.size()>1)
        {
            prev.push_back(next.front());
            next.pop_front();
        }
        
        curr=next.front();
        next.pop_front();
        
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */