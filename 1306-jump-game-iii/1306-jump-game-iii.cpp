class Solution 
{
private:
    vector<bool> visited;
    
    bool canReachUtil(vector<int>& arr,int index)
    {
        if(arr[index]==0)
        {
            return true;
        }
        
        visited[index]=true;
        
        if(index-arr[index]>=0 && !visited[index-arr[index]])
        {
            if(canReachUtil(arr,index-arr[index]))
            {
                return true;
            }
        }
        
        if(index+arr[index]<arr.size() && !visited[index+arr[index]])
        {
            if(canReachUtil(arr,index+arr[index]))
            {
                return true;
            }
        }
        
        visited[index]=false;
        
        return false; //Recursive Solution 
        //TC: O(2^n) //as 2 Recursion calls for every index
        //SC: O(n)+O(n)auxiliary stack space
    }
public:
    bool canReach(vector<int>& arr, int start) 
    {
        visited.assign(arr.size(),false);
        
        return canReachUtil(arr,start);
    }
};