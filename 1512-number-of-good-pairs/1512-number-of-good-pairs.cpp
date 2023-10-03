class Solution 
{
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        unordered_map<int,vector<int>> umap;
        
        for(int i=0; i<nums.size(); i++)
        {
            umap[nums[i]].push_back(i);
        }
        
        // for(auto x:umap)
        // {
        //     cout<<x.first<<" -> ";
        //     for(auto y:x.second)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int ans=0;
        for(auto x:umap)
        {
            int n=x.second.size();
            int val=(n*(n-1))/2;
            ans=ans+val;
        }
        
        return ans;
    }
};