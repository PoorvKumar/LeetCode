class Solution 
{
private:    
    bool compare(vector<int> & v1,vector<int>& v2)
    {
        if(v1.size()!=v2.size())
        {
            return false;
        }
        
        int n=v1.size();
        while(n--)
        {
            if(v1[n]!=v2[n])
            {
                return false;
            }
        }
        
        return true;
    }
    
    void combinationSumHelper(vector<int>& cand,int target,vector<vector<int>>& ans)
    {
        if(target<1)
        {
            return ;
        }
        
        for(int i=0; i<cand.size(); i++)
        {
            if(target<cand[i])
            {
                return; 
            }
            
            if(target==cand[i]) 
            { 
                ans.push_back({target});
                return; //sorted other elements in candidates greater which need not be traversed
            }
            
            int x=target-cand[i];
            
            vector<vector<int>> vec;
            combinationSumHelper(cand,x,vec); 
            
            if(!vec.empty())
            {
                for(int j=0; j<vec.size(); j++)
                {
                    vec[j].push_back(cand[i]);
                    
                    sort(vec[j].begin(),vec[j].end()); //logic to add only those which not present
                    bool flag=false;  //sort() to compare objects of type class vector
                    for(auto &x:ans)
                    {
                        if(compare(vec[j],x))
                        {
                            flag=true;
                        }
                    }
                    
                    if(!flag) 
                    {
                        ans.push_back(vec[j]);
                    }
                }
            }
        }
        
        return ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>> ans;
        combinationSumHelper(candidates,target,ans);
        
        return ans;
        
//         for(int i=0; i<ans.size(); i++)
//         {
//             sort(ans[i].begin(),ans[i].end());
//         }
        
//         int j=0;
//         for(int i=1; i<ans.size(); i++)
//         {
//             while(compare(ans[j],ans[i]))
//             {
//                 i++;
//             }
//             if(i<ans.size())
//             {
//                 ans[++j]=ans[i];
//             }
//         }
        
//         int n=ans.size();
        
//         for(int i=j+1; i<n; i++)
//         {
//             ans.erase(ans.begin()+i);
//         }
        
        // answer.assign(ans.begin(),ans.begin()+j); //[beginAddress,endAddress) 
        // ans.erase(ans.begin()+j,ans.end()); //above doesn't work as contiguous memory allocation and object of type class vector<vector<int>> so not just +1
        
        // return ans;
    }
};