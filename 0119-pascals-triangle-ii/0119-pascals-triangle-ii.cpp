class Solution 
{
private:
    vector<int> getRowUtil(int rowIndex)
    {
        if(rowIndex==0)
        {
            return vector<int>({1});
        }
        
        vector<int> prev=getRowUtil(rowIndex-1);
        vector<int> curr(rowIndex+1,0);
        
        curr.front()=1;
        curr.back()=1;
        
        for(int i=1; i<rowIndex; i++)
        {
            curr[i]=prev[i]+prev[i-1];
        }
        
        return curr;
    }
public:
    vector<int> getRow(int rowIndex) 
    {
        return getRowUtil(rowIndex);
    }
};