class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        vector<int> vec(n,0);
        // stack<int> stk;
        queue<int> q;
        // q.push(matrix[0][0]);
        for(int i=0; i<n; i++)
        {
            int j=i;
            while(j>=0)
            {
                q.push(matrix[j][i]);
                j--;
            }
        }
        
        for(int i=0; i<n; i++)
        {
            //initialise vec //bottom to up each column becomes top to bottom each row
            int j=n-1;
            for(auto &x:vec)
            {
                x=matrix[j--][i];
            }
            
            j=i;
            while(j>=0)
            {
                vec[n-1-j]=q.front();
                q.pop();
                j--;
            }
            
            matrix[i]=vec;
        }
        
        return ;
    }
};