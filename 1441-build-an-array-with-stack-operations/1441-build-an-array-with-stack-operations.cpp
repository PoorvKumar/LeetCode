class Solution 
{
private:
    vector<string> res;
    
    void buildArrayUtil(vector<int>& target,int index,int val,int n)
    {
        if(index==target.size())
        {
            return ;
        }
        
        if(val>n)
        {
            return ;
        }
        
        if(target[index]==val)
        {
            res.push_back("Push");
            buildArrayUtil(target,index+1,val+1,n);
        }
        else
        {
            res.push_back("Push");
            res.push_back("Pop");
            buildArrayUtil(target,index,val+1,n);
        }
        
        return ; //Recursive Solution
        //TC: O(n)
        //SC: O(n)
    }
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        // buildArrayUtil(target,0,1,n);
        
        int val=1;
        
        for(int i=0; i<target.size(); i++)
        {
            if(target[i]==val)
            {
                res.push_back("Push");
                val++;
            }
            else
            {
                while(target[i]!=val)
                {
                    res.push_back("Push");
                    res.push_back("Pop");
                    val++;
                }
                
                res.push_back("Push");
                val++;
            }
        }
        
        return res;
    }
};