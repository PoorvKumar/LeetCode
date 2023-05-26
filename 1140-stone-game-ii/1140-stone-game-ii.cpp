class Solution 
{
private:
    unordered_map<int,unordered_map<int,unordered_map<bool,int>>> umap; //umap[index][M][alice]
    
    int stoneGameIIUtil(vector<int>& piles,int index,int M,bool alice)
    {
        if(index>=piles.size())
        {
            return 0;
        }
        
        if(umap.count(index) && umap[index].count(M) && umap[index][M].count(alice))
        {
            return umap[index][M][alice];
        }
        
        int ans=alice?0:INT_MAX;
        int sum=0;
        
        for(int i=1; i<=2*M; i++)
        {
            sum=alice?sum+piles[index+i-1]:0;
            int val=sum+stoneGameIIUtil(piles,index+i,max(M,i),!alice);
            ans=alice?max(ans,val):min(ans,val);
            
            if(index+i>=piles.size())
            {
                break;
            }
        }
        
        // return ans; //Recursive Solution
        //TC: O(2M*2M^n) //as M Recursion calls for every index
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[index][M][alice]=ans; //Top-Down DP approach -> Recursion + memoization
        //TC: O(2*M*n*2) //as for every index for every M for every alice Recursion calls Memoized
        //SC: O(n*2*M*2)+O(n)auxiliary stack space
    }
public:
    int stoneGameII(vector<int>& piles) 
    {
        return stoneGameIIUtil(piles,0,1,true);
    }
};