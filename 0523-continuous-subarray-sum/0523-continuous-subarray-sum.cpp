class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixMod;
        prefixMod[0]=-1;
        long long sum=0;
        int ans=0;

        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            int rem=sum%k;

            if(prefixMod.count(rem))
            {
                ans=max(ans,i-prefixMod[rem]);
            }

            if(!prefixMod.count(rem)) prefixMod[rem]=i; //only the first entry as we need to longest contigous subarray
        }

        return ans>1;
    }
};