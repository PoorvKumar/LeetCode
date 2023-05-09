class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> res;
        
        int m=matrix.size();
        int n=matrix[0].size();
        
//         if(m==1 || n==1)
//         {
//             for(auto x:matrix)
//             {
//                 for(auto y:x)
//                 {
//                     res.push_back(y);
//                 }
//             }
            
//             return res;
//         }
        
        int loops=min(m,n);
        loops=loops/2+loops%2;
        // cout<<loops<<endl;
        
        int i=0; 
        int j=0;
        // vector<vector<bool>> visited(m,vector<bool>(n,false));
        
        // int rightBound=n-1;
        // int downBound=m-1;
        // int leftBound=0;
        // int upBound=0;
        
        int x=n-1; //number of elements in x-direction from one side of spiral
        int y=m-1; //number of elements in y-direction from one side of spiral
        
        while(loops--)
        {
            if(m==1 || n==1)
            {
                if(m==1)
                {
                    for(int index=j; index<j+n; index++)
                    {
                        res.push_back(matrix[i][index]);
                    }
                    
                    return res;
                }
                
                for(int index=i; index<i+m; index++)
                {
                    res.push_back(matrix[index][j]);
                }
                
                return res;
            }
            
            //right
            x=n-1;
            while(x>0 && x--)
            {
                res.push_back(matrix[i][j]);
                j++;
            }
            
            //down
            y=m-1;
            while(y>0 && y--)
            {
                res.push_back(matrix[i][j]);
                i++;
            }
            
            //left
            x=n-1;
            while(x>0 && x--)
            {
                res.push_back(matrix[i][j]);
                j--;
            }
            
            //up
            y=m-1;
            while(y>0 && y--)
            {
                res.push_back(matrix[i][j]);
                i--;
            }
            
            i++; //move down
            j++; //to inner spiral
            
            m=m-2;
            n=n-2;
        }
        
        return res;
    }
};