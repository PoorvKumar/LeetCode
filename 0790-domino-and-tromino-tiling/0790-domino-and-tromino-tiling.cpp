class Solution 
{
private:
    unsigned long long M=1e9+7;
    
    unordered_map<int,unordered_map<bool,int>> umap; //umap[index][semifilled]
    
    int numTilingsUtil(int n,int index,bool semifilled)
    {
        if(index>=n)
        {
            return 1;
        }
        
        if(umap.count(index) && umap[index].count(semifilled))
        {
            return umap[index][semifilled];
        }
        
        int ans=0;
        
        if(!semifilled)
        {
            if(n-index>=1)
            {
                //domino
                ans=ans%M+numTilingsUtil(n,index+1,semifilled)%M;
            }
            
            ans%=M;
            
            if(n-index>=2)
            {
                //domino
                ans=ans%M+numTilingsUtil(n,index+2,semifilled)%M;
                ans%=M;
                
                if(n-index>2)
                {
                    //tromino
                    long long val=numTilingsUtil(n,index+1,!semifilled)%M;
                    val=val%M*2;
                    ans=ans%M+val%M; //mirror
                }
                
                ans%=M;
            }
        }
        else
        {
            if(n-index>2)
            {
                //domino
                long long val=numTilingsUtil(n,index+1,semifilled)%M;
                ans=ans%M+val%M;
            }
            
            ans%=M;
            
            if(n-index>=2)
            {
                //tromino
                long long val=numTilingsUtil(n,index+2,!semifilled)%M;
                ans=ans%M+val%M;
            }
            
            ans%=M;
        }
        
        // return ans; //Recursive Solution
        //TC: O(2^n) //as 2(domino,tromino) Recursion calls for every index
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[index][semifilled]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*2) //as for every index for every semifilled Recursion calls Memoized
        //SC: O(n*2)+O(n)auxiliary stack space
    }
public:
    int numTilings(int n) 
    {
        return numTilingsUtil(n,0,false);
    }
};