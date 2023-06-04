class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        unordered_set<int> rows;
        unordered_set<int> columns;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(rows.count(i) || columns.count(j))
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        return ;
    }
};