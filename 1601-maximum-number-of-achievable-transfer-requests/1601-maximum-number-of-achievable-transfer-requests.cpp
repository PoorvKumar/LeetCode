class Solution 
{
private:
    int ans=0;
    
    void maximumRequestsUtil(int n,vector<vector<int>>& requests,vector<int>& vec,int index,int count)
    {
        if(index>=requests.size())
        {
            for(auto x:vec)
            {
                if(x)
                {
                    return ;
                }
            }
            
            ans=max(ans,count);
            return ;
        }
        
        //decline the request
        maximumRequestsUtil(n,requests,vec,index+1,count);
        
        //accept the request
        vec[requests[index][0]]--;
        vec[requests[index][1]]++;
        
        maximumRequestsUtil(n,requests,vec,index+1,count+1);
        
        vec[requests[index][0]]++;
        vec[requests[index][1]]--;
        
        return ;
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) 
    {
        vector<int> vec(n,0);
        
        maximumRequestsUtil(n,requests,vec,0,0);
        return ans;
    }
};