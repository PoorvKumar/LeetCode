class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        if(k==0)
        {
            return false;
        }
        
        if(nums.size()<=k)
        {
            unordered_set<int> uset(nums.begin(),nums.end());
            if(nums.size()>uset.size())
            {
                return true;
            }
            return false;
        }
        
        // unordered_set<int> uset(nums.begin(),nums.begin()+k-1); //not this 
        
        unordered_set<int> uset(nums.begin(),nums.begin()+k); //[beginAddress,endAddress)
        int n=nums.size();
        // cout<<uset.size()<<endl;
        
        for(int i=0; i<n-k; i++) 
        {
            uset.insert(nums[i+k]);
            if(uset.size()<k+1)
            {
                // for(auto x:uset)
                // {
                //     cout<<x<<" ";
                // }
                // cout<<endl;
                return true;
            }
            uset.erase(nums[i]);
        }
        
        // for(auto it=nums.begin(); it!=nums.end()-k; it++)
        // {
        //     unordered_set<int> uset(it,it+k+1); //[beginAddress,endAddress)
        //     if(uset.size()<k+1)
        //     {
        //         return true; //O(n^2) for creating object uset of type class unordered_set
        //     }
        //     uset.clear();
        // }
        
        return false;
    } 
};