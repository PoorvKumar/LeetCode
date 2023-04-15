class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[index][k]
    
    int maxValueOfCoinsUtil(vector<vector<int>>& piles,int index,int k)
    {
        if(k==0)
        {
            return 0;
        }
        
        if(index>=piles.size())
        {
            return INT_MIN;
        }
        
        if(umap.count(index) && umap[index].count(k))
        {
            return umap[index][k];
        }
        
        int exclude=maxValueOfCoinsUtil(piles,index+1,k);
        int include=0;
        
        int s=piles[index].size();
        // int n=min(k,s);
        
        for(int i=1; i<=min(k,s); i++)
        {
            int val=piles[index][i-1]+maxValueOfCoinsUtil(piles,index+1,k-i);
            include=max(include,val);
        }
        
        // return max(exclude,include); //Recursive Solution
        //TC: O(k*2^n) //as 2 (exclude,include) calls for every index && k calls for every index in piles[index]
        //SC: O(n*k)+O(n*k)auxiliary stack space
        
        return umap[index][k]=max(exclude,include); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*k) //as for every indeeex for eveery k Reecursion calls Memoized
        //SC: O(n*k)+O(n*k)auxiliary stack space
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        //prefixSum
        for(auto &x:piles)
        {
            int sum=0;
            for(auto &y:x)
            {
                sum=sum+y;
                y=sum;
            }
        }
        
        return maxValueOfCoinsUtil(piles,0,k);
    }
};