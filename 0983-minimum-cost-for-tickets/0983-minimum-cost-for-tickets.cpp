class Solution 
{
private:
    unordered_map<int,int> umap; //umap[index]
    
    int mincostTicketsUtil(vector<int>& days,vector<int>& costs,int index)
    {
        if(index>=days.size())
        {
            return 0;
        }
        
        if(umap.count(index))
        {
            return umap[index];
        }
        
        int one=costs[0]+mincostTicketsUtil(days,costs,index+1);
        
        int k=index;
        while(k<days.size() && days[k]<days[index]+7)
        {
            k++;
        }
        
        int seven=costs[1]+mincostTicketsUtil(days,costs,k);
        
        k=index;
        while(k<days.size() && days[k]<days[index]+30)
        {
            k++;
        }
        
        int thirty=costs[2]+mincostTicketsUtil(days,costs,k);
        
        int ans=min(one,seven);
        ans=min(ans,thirty);
        
        // return ans; //Recursive Solution
        //TC: O(3^n) //as 3 (one,seven,thrity) calls for every index
        //SC: O(n) + O(n)auxilliary stack space
        
        return umap[index]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n) //as for every index Recursion calls Memoized
        //SC: O(n) + O(n)auxiliary stack space
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        return mincostTicketsUtil(days,costs,0);
    }
};