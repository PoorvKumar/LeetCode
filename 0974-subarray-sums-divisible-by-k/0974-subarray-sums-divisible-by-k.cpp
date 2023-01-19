class Solution 
{
private:
    unordered_map<int,unordered_set<int>> umap;
    
    void subArraysUtil(vector<int>& nums,int k,int sum,int &res,int start,int end) //exponential
    {
        // if(nums.size()==0) // 38 /73 testcases passed
        // {
        //     return;
        // }
        
        if(start>end || start>=nums.size() || end<0)
        {
            return ;
        }
        
        int n=end-start;
        
        if(umap.count(start) && umap[start].count(end-start))
        {
            return ;
        }
        
        if(sum%k==0)
        {
            // for(auto x:nums)
            // {
            //     cout<<x<<" ";
            // }
            // cout<<" -> "<<sum<<endl;
            // for(int i=start; i<=end; i++)
            // {
            //     cout<<nums[i]<<" ";
            // }
            // cout<<endl;
            res++;
            umap[start].insert(end-start); //very cool
        }
        
        subArraysUtil(nums,k,sum-nums[start],res,start+1,end);
        subArraysUtil(nums,k,sum-nums[end],res,start,end-1);
        
//         int x=nums[0];
//         // nums.erase(nums.begin());
//         nums.pop_front();
//         subArraysUtil(nums,k,sum-x,res,start+1);
//         // nums.insert(nums.begin(),x);
//         nums.push_front(x);
        
//         x=nums[n-1];
//         nums.pop_back();
//         subArraysUtil(nums,k,sum-x,res,start);
//         nums.push_back(x);
        
        return;
    }
public:    
    int subarraysDivByK(vector<int>& nums, int k)
    {
        if(nums.size()==1)
        {
            if(nums[0]%k==0)
            {
                return 1;
            }
            return 0;
        }
        
//         int sum=accumulate(nums.begin(),nums.end(),0);
//         int res=0;
        
//         // deque<int> dq(nums.begin(),nums.end());
//         subArraysUtil(nums,k,sum,res,0,nums.size()-1); //exponential time complexity so need better
        
//         int sum=0;
//         int res=0;
        
//         for(int i=0; i<nums.size(); i++) //Brute Force //O(n^2) faster than above 66 / 73 testcases passed
//         {
//             sum=0;
//             for(int j=i; j<nums.size(); j++) //running sum //learnt about prefixSum 
//             {
//                 sum=sum+nums[j];
//                 if(sum%k==0)
//                 {
//                     // cout<<i<<" "<<j<<endl; 
//                     res++;
//                 }
//             }
//             // sum=sum-nums[i];
//         }
        
        int prefixMod=0; //Time Complexity: O(n+k)
        int res=0;
        
        vector<int> modGroup(k); //O(k)
        modGroup[0]=1;
        
        for(int i=0; i<nums.size(); i++) //O(n)
        {
            prefixMod=(prefixMod + nums[i]%k + k)%k;
            res=res+modGroup[prefixMod];
            modGroup[prefixMod]++;
        }
        
        return res;
    }
};