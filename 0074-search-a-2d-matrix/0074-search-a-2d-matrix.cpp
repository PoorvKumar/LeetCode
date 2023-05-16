class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int lowX=0, highX=m-1;
        int lowY=0, highY=n-1;
        
        int midX;
        int midY;

        while(lowX<=highX && lowY<=highY)
        {
            midX=(lowX+highX)/2;
            midY=(lowY+highY)/2;
            
            if(matrix[midX][midY]==target)
            {
                return true;
            }
            else if(matrix[midX][midY]<target)
            {
                if(matrix[midX][highY]<target)
                {
                    lowX=midX+1;
                }
                else
                {
                    lowY=midY+1;
                }
            }
            else
            {
                if(matrix[midX][lowY]>target)
                {
                    highX=midX-1;
                }
                else
                {
                    highY=midY-1;
                }
            }
        }
        
        return false; //Binary Search
        //TC: O(log(m+n))
        //SC: O(m*n)
    }
};