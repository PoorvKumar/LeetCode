class Solution 
{
private:
    bool compare(vector<int>& v1,vector<int>& v2)
    {
        if(v1.size()!=v2.size())
        {
            return false;
        }
        
        for(int i=0; i<v1.size(); i++)
        {
            if(v1[i]!=v2[i])
            {
                return false;
            }
        }
        
        return true;
    }
    
    unordered_map<int,vector<vector<int>>> umap;
    
    void findSubsequenceUtil(vector<int>& nums,int index,int x,vector<vector<int>>& res,vector<int>& vec)
    {
        if(index>=nums.size())
        {
            // if(umap.count(vec.size()))
            // {
            //     for(auto x:umap[vec.size()])
            //     {
            //         if(compare(x,vec))
            //         {
            //             return;
            //         }
            //     }
            // }
            // umap[vec.size()].push_back(vec);
            if(vec.size()>1)
            {
                if(res.empty())
                {
                    res.push_back(vec);
                }
                
                if(!compare(res[res.size()-1],vec))
                {
                    res.push_back(vec);
                }
            }
            return;
        }
        
        vector<int> ans=vec;
        findSubsequenceUtil(nums,index+1,x,res,ans); //exclusion call before inclusion call gives correct 
        if(nums[index]>=x)                            //answer for test case 2
        {                                             //also it makes sure non-decreasing subsequence
            ans.push_back(nums[index]);
            findSubsequenceUtil(nums,index+1,nums[index],res,ans);
        }
        // findSubsequenceUtil(nums,index+1,x,res,ans);
        
        return;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> vec;
        
        findSubsequenceUtil(nums,0,-101,res,vec);
        
        sort(res.begin(),res.end());
        vector<vector<int>> result;
        for(auto x:res)
        {
            if(result.empty())
            {
                result.push_back(x);
            }
            
            if(!compare(result[result.size()-1],x))
            {
                result.push_back(x);
            }
        }
        
        // return res;
        return result;
    }
};