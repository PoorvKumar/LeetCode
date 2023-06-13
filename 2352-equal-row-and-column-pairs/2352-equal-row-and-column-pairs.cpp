class Solution 
{
private:
    bool isSame(vector<int>& vec1,vector<int>& vec2)
    {
        if(vec1.size()!=vec2.size())
        {
            return false;
        }
        
        for(int i=0; i<vec1.size(); i++)
        {
            if(vec1[i]!=vec2[i])
            {
                return false;
            }
        }
        
        return true;
    }
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
//         vector<vector<int>> rows;
//         vector<vector<int>> cols;
        
//         for(auto x:grid)
//         {
//             rows.push_back(x);
//         }
        
        int n=grid.size();
        
        int ans=0;
        
        for(int i=0; i<n; i++)
        {
            vector<int> vec;
            for(int j=0; j<n; j++)
            {
                vec.push_back(grid[j][i]);
            }
            
            for(auto &x:grid)
            {
                // if(isSame(x,vec))
                // {
                //     ans++;
                // }
                if(x==vec)
                {
                    ans++;
                }
            }
            
            // cols.push_back(vec);
        }
        
        return ans;
    }
};