class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> stk;
        
        for(auto x:asteroids)
        {
            if(!stk.empty() && stk.top()>0 && x<0)
            {
                if(stk.top()+x>=0)
                {
                    if(stk.top()+x==0)
                    {
                        stk.pop();
                    }
                    continue;
                }
                
                while(!stk.empty() && stk.top()>0 && stk.top()+x<0)
                {
                    stk.pop();
                }
                
                if(!stk.empty() && stk.top()+x>=0)
                {
                    if(stk.top()+x==0)
                    {
                        stk.pop();
                    }
                    continue;
                }
            }
            
            stk.push(x);
        }
        
        vector<int> res;
        
        while(!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        
        reverse(res.begin(),end(res));
        
        return res;
    }
};