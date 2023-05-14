class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        unordered_map<int,unordered_map<int,unordered_set<int>>> umap; //umap[x][y]
        
        for(int i=0; i<nums.size(); i++)
        {
            int left=i+1;
            int right=nums.size()-1;
            while(left<right)
            {
                int val=nums[i]+nums[left]+nums[right];
                if(val==0)
                {
                    if(umap.count(nums[i]) && umap[nums[i]].count(nums[left]) && umap[nums[i]][nums[left]].count(nums[right]))
                    {
                        left++;
                        right--;
                        continue;
                    }
                    
                    res.push_back(vector<int>({nums[i],nums[left],nums[right]}));
                    umap[nums[i]][nums[left]].insert(nums[right]);
                    
                    left++;
                    right--;
                }
                else if(val<0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        
        return res;
    }
};