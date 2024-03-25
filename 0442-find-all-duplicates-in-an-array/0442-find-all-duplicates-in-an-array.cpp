class Solution 
{
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        vector<int> res;
        
        //constant extra soace
        //linear time
        vector<bool> hasAppeared(1e5+1,false); //technically constant space as we know the upper limit of int n;
        
        for(auto x:nums)
        {
            if(hasAppeared[x])
            {
                res.push_back(x);
            }
            
            hasAppeared[x]=true;
        }
        
        return res;
    }
};