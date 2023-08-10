class Solution 
{
private:
    vector<int> removeDuplicates(vector<int>& nums)
    {
        unordered_set<int> uset;
        
        vector<int> vec;
        
        for(auto x:nums)
        {
            if(!uset.count(x))
            {
                vec.push_back(x);
                uset.insert(x);
            }
        }
        
        return vec;
    }
public:
    bool search(vector<int>& nums, int target) 
    {
//         for(auto x:nums)
//         {
//             if(x==target)
//             {
//                 return true;
//             }
//         }
        
//         return false;
        
        if(nums.size()==1)
        {
            return nums[0]==target;
        }
        
        nums=removeDuplicates(nums);
        
        int low=0;
        int high=nums.size()-1;
        int mid=(low+high)/2;
        
        while(low<high)
        {
            if(mid+1<nums.size() && nums[mid+1]<nums[mid])
            {
                break;
            }
            
            if(nums[low]<=nums[mid])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
            mid=(low+high)/2;
        }
        
        int k=mid;
        // cout<<k<<endl;
        
        // if(k==nums.size()-1)
        // {
        //     return binary_search(nums.begin(),nums.begin()+k+1,target);
        // }
        
        return binary_search(nums.begin(),nums.begin()+k+1,target) || binary_search(nums.begin()+k+1,nums.end(),target);
        //TC: O(logn1)+O(logn2) -> O(log(n1*n2))
        //SC: O(1)
    }
};