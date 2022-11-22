class Solution 
{
private:
    unordered_map<int,int> umap;
    
    int numSquareUtil(vector<int>& vec,int n)
    {
        if(n==0) //Base Case
        {
            return 0;
        }
        
        if(n<0) //Base Case
        {
            return INT_MAX;
        }
        
        int res=INT_MAX;
        
        for(int i=vec.size()-1; i>=0; i--)
        {
            int x=umap.count(n-vec[i])?umap[n-vec[i]]:numSquareUtil(vec,n-vec[i]);
            if(x!=INT_MAX && x+1<res)
            {
                res=x+1;
            }
        }
        
        return umap[n]=res;
    }
    
public:
    int numSquares(int n) 
    {
        vector<int> vec;
        int i=1;
        
        while(i*i<=n)
        {
            vec.push_back(i*i);
            i++;
        }
        
        // for(auto x:vec)
        // {
        //     cout<<x<<" ";
        // }
        
        
        // return 1;
        return numSquareUtil(vec,n);
    }
};

