class Solution 
{
private:
    unordered_map<int,long long> umap; //umap[index]
    
    long long mostPointsUtil(vector<vector<int>>& questions,int index)
    {
        if(index>=questions.size())
        {
            return 0;
        }
        
        if(umap.count(index))
        {
            return umap[index];
        }
        
        long long skip=mostPointsUtil(questions,index+1);
        
        int points=questions[index][0];
        int brainpower=questions[index][1];
        
        long long solve=points+mostPointsUtil(questions,index+brainpower+1);
        
        // return max(skip,solve); //Recursive Solution
        //TC: O(2^n) //as 2 (skip,solve) calls for every index
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[index]=max(skip,solve); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n) //as for evry index Recursion calls Memoized
        //SC: O(n)+O(n)auxiliary stack space
    }
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        return mostPointsUtil(questions,0);
    }
};