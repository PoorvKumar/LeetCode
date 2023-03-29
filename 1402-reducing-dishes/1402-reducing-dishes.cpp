class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap;
    
    int maxSatisfactionUtil(vector<int>& satisfaction,int index,int time)
    {
        if(index==satisfaction.size()-1)
        {
            if(time*satisfaction[index]>0)
            {
                return time*satisfaction[index];
            }
            return 0;
        }
        
        if(umap.count(index) && umap[index].count(time))
        {
            return umap[index][time];
        }
        
        int exclude=0+maxSatisfactionUtil(satisfaction,index+1,time);
        int include=time*satisfaction[index]+maxSatisfactionUtil(satisfaction,index+1,time+1);
        
        // return max(exclude,include); //Recursive Solution
        //TC: O(2^n) //as 2 (incldue,exlcude) calls for every index
        //SC: O(n) + O(n)auxiliary space
        
        return umap[index][time]=max(exclude,include); //Top-Dpown DP approach -> Recursion + Memoization
        //TC: O(n*time) //as for every index for every time Recursion calls Memoized
        //SC: O(n*time) + O(n)auxiliary stack space
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) 
    {
        sort(satisfaction.begin(),satisfaction.end());
        
        return maxSatisfactionUtil(satisfaction,0,1);
    }
};