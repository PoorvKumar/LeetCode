class Solution 
{
private:
    int m;
    int n;
    
    bool check(vector<vector<int>> &matrix,int i,int j)
    {
        if(i>=m-1 || j>=n-1)
        {
            return true;
        }
        
        if(matrix[i][j]==matrix[i+1][j+1])
        {
            return check(matrix,i+1,j+1);
        }
        else 
        {
            return false;
        }
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        m=matrix.size();
        n=matrix[0].size();
        
        for(int i=0; i<m; i++)
        {
            if(!check(matrix,i,0))
            {
                return false;
            }
        }
        
        for(int i=1; i<n; i++)
        {
            if(!check(matrix,0,i))
            {
                return false;
            }
        }
        
        return true;
    }
};