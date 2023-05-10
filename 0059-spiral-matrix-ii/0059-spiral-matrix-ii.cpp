class Solution 
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> mat(n,vector<int>(n,0));
        
        int val=1;
        int k;
        
        int i=0; int j=0;
        
        int spirals=n/2+n%2;
        
        while(spirals--)
        {
            if(n==1)
            {
                mat[i][j]=val;
                return mat;
            }
            
            //right
            k=n-1;
            while(k>0 && k--)
            {
                mat[i][j]=val++;
                j++;
            }
            
            //down
            k=n-1;
            while(k>0 && k--)
            {
                mat[i][j]=val++;
                i++;
            }
            
            //left
            k=n-1;
            while(k>0 && k--)
            {
                mat[i][j]=val++;
                j--;
            }
            
            //up
            k=n-1;
            while(k>0 && k--)
            {
                mat[i][j]=val++;
                i--;
            }
            
            i++; //move down
            j++; //to inner spiral
            
            n=n-2;
        }
        
        return mat;
    }
};