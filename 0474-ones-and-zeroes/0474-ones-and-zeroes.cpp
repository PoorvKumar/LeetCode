class Solution 
{
private:
    vector<pair<int,int>> vec;
    
    unordered_map<int,unordered_map<int,unordered_map<int,int>>> umap; //umap[index][m][n]
    
    int findMaxUtil(int index,int m,int n)
    {
        if(index>=vec.size())
        {
            return 0;
        }
        
        if(umap.count(index) && umap[index].count(m) && umap[index][m].count(n))
        {
            return umap[index][m][n];
        }
        
        int exclude=findMaxUtil(index+1,m,n);
        int include=0;
        if(vec[index].first<=m && vec[index].second<=n)
        {
            include=1+findMaxUtil(index+1,m-vec[index].first,n-vec[index].second);
        }
        
        int ans=max(exclude,include);
        // return ans; //Recursive Solution
        //TC: O(2^N) //as 2 (exclude,include) Recursion calls for every index
        //SC: O(N)+O(N)auxiliary stack space
        
        return umap[index][m][n]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(N*m*n) //as for every index for every m for every n Recursion calls Memoized
        //SC: O(N*m*n)+O(N)auxilary stack space
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        for(auto &x:strs)
        {
            int one=0;
            for(int i=0; i<x.length(); i++)
            {
                if(x[i]=='1')
                {
                    one++;
                }
            }
            
            int zero=x.length()-one;
            
            vec.push_back({zero,one});
        }
        
        // for(auto x:vec)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        
        return findMaxUtil(0,m,n);
    }
};