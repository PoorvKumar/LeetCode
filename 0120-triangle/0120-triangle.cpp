class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap;
public:
    int minimumTotal(vector<vector<int>>& triangle,int i=0,int j=0) 
    {
        if(i>=triangle.size())  //Top-Down DP approach-> Recursion + Memoizatioon
        {
            return 0;    
        }
        
        if(umap.count(i)==1 && umap[i].count(j))
        {
            return umap[i][j];
        }
        
        umap[i][j]=triangle[i][j]+min(minimumTotal(triangle,i+1,j),minimumTotal(triangle,i+1,j+1));
        return umap[i][j];
    }
};