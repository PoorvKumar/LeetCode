class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int n=height.size();
        int i=0;
        int j=n-1;
        
        int maxim=0;
        
        while(i<j)  //Two Pointer Approach but noit Brute Force which takes O(n^2) time complexity
        {
            if(height[i]==0)
            {
                i++;
                continue;
            }
            if(height[j]==0)
            {
                j--;
                continue;
            }
            int x=0;
            if(height[i]>=height[j]) //move towards greater line
            {
                x=height[j]*(j-i);
                j--;
            }
            else
            {
                x=height[i]*(j-i);
                i++;
            }
            maxim=max(maxim,x);
        }
        
        return maxim;
    }
};