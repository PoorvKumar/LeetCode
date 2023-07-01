class Solution 
{
private:
    int distributeCookiesUtil(vector<int>& cookies,int index,vector<int>& vec,int k)
    {
        if(index>=cookies.size())
        {
            return *max_element(vec.begin(),vec.end());
        }
        
        int ans=INT_MAX;
        
        for(int i=0; i<k; i++)
        {
            vec[i]=vec[i]+cookies[index];
            int val=distributeCookiesUtil(cookies,index+1,vec,k);
            ans=min(ans,val);
            vec[i]=vec[i]-cookies[index];
        }
        
        return ans;
    }
public:
    int distributeCookies(vector<int>& cookies, int k) 
    {
        vector<int> vec(k,0);
        
        return distributeCookiesUtil(cookies,0,vec,k);
    }
};