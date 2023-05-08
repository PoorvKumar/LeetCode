class Solution 
{
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int sum=0;
        
        int n=mat.size();
        int j=0;
        
        for(int i=0; i<n; i++)
        {
            sum=sum+mat[i][j]+mat[i][n-1-i];
            j++;
        }
        
        if(n%2!=0)
        {
            sum=sum-mat[n/2][n/2];
        }
        
        return sum;
    }
};