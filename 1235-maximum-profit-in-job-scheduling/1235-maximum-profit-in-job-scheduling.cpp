class Solution 
{
private:
    vector<vector<int>> vec;
    unordered_map<int,int> umap; //umap[index]
    vector<int> dp;
    
    int jobSchedulingUtil(int index)
    {
        if(index>=vec.size())
        {
            return 0;
        }
        
        // if(umap.count(index))
        // {
        //     return umap[index];
        // }
        
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        
        int exclude=jobSchedulingUtil(index+1);
        int include=0;
        
        vector<int> temp={vec[index][1],0,0};
        
        int i=lower_bound(vec.begin(),vec.end(),temp)-begin(vec);
        
        include=vec[index][2]+jobSchedulingUtil(i);
        
        // return max(exclude,include); //Recursive Solution
        //TC: O(2^(nlogn)) //as for every index 2(exclude,include) Recursion calls //we search the next i index by implementing lower_bound() function and using binary search
        //SC: O(n)+O(n)auxiliary stack
        
        // return umap[index]=max(exclude,include); //Top-Down DP aproach -> Recursion + Memoization
        return dp[index]=max(exclude,include); //Top-Down DP aproach -> Recursion + Memoization
        //TC: O(n*logn) //as for every index Recursion calls Memoized
        //SC: O(n)+O(n)auxiliary stack space
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        for(int i=0; i<startTime.size(); i++)
        {
            vec.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        sort(vec.begin(),end(vec));
        
        int n=vec.size();
        dp.assign(n+1,-1);
        
        return jobSchedulingUtil(0);
    }
};