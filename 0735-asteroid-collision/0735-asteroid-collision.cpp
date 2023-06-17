class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> stk;
        
        for(auto x:asteroids)
        {
            if(x<0 && !stk.empty() && stk.top()>0)
            {
                int val=x+stk.top();
                bool flag=true;
                
                while(val<0)
                {
                    stk.pop();
                    
                    if(!stk.empty() && stk.top()>0)
                    {
                        val=x+stk.top();
                        // if(val==0)
                        // {
                        //     stk.pop();
                        //     break;
                        // }
                    }
                    else
                    {
                        stk.push(x);
                        flag=false;
                        break;
                    }
                }
                
                if(flag && val==0)
                {
                    stk.pop();
                }
            }
            else
            {
                stk.push(x);
            }
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