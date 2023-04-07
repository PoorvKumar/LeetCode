class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap;
    
    int longestCommonUtil(string& text1,string& text2,int x,int y)
    {
        // if(x==text1.length()-1 && y==text2.length()-1)
        // {
        //     return text1[x]==text2[y];
        // }
        
        if(x==text1.length()-1 || y==text2.length()-1) //base case
        {
            if(x==text1.length()-1)
            {
                while(y<text2.length())
                {
                    if(text1[x]==text2[y])
                    {
                        return 1;
                    }
                    y++;
                }
                return 0;
            }
            
            while(x<text1.length())
            {
                if(text1[x]==text2[y])
                {
                    return 1;
                }
                x++;
            }
            
            return 0;
        }
        
        if(umap.count(x) && umap[x].count(y))
        {
            return umap[x][y];
        }
        
        if(text1[x]==text2[y])
        {
            return umap[x][y]= 1+longestCommonUtil(text1,text2,x+1,y+1);
        }
        
        int t1=longestCommonUtil(text1,text2,x+1,y);
        int t2=longestCommonUtil(text1,text2,x,y+1);
        
        // return max(t1,t2); //Recursive Solution
        
        return umap[x][y]=max(t1,t2); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(x*y) //as for every index in text1 for every indedx in text2 Recursion calls Memoized
        //SC: O(x*y)
    }
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        return longestCommonUtil(text1,text2,0,0);
    }
};