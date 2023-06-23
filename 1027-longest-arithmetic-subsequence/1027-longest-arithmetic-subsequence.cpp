class Solution 
{
public:
    int longestArithSeqLength(vector<int>& nums) 
    {
        unordered_map<int,unordered_map<int,int>> umap;
        
        int res=INT_MIN;
        
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                int a=nums[i];
                int b=nums[j];
                int diff=b-a;
                
                if(umap[diff].count(i))
                {
                    umap[diff][j]=umap[diff][i]+1;
                }
                else
                {
                    umap[diff][j]=2;
                }
                
                res=max(res,umap[diff][j]);
            }
        }
        
        return res;
    }
};