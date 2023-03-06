class Solution 
{
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        unordered_set<int> uset(arr.begin(),arr.end());
        
        int val=arr[arr.size()-1]+k;
        
        for(int i=1; i<=val; i++)
        {
            if(uset.count(i)==0)
            {
                k--;
            }
            if(k==0)
            {
                return i;
            }
        }
        
        return -1; //TC: O(n) SC: O(n)
    }
};