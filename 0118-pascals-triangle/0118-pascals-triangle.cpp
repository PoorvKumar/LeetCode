class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans(numRows);
        
        ans[0]=vector<int>(1,1);
        // ans[0]={1};
        
        for(int i=1; i<numRows; i++)
        {
            ans[i]=vector<int>(i+1,1); //{1 , , , , 1}
            
            for(int j=1; j<i; j++)
            {
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
        }
        
        return ans;
    }
};