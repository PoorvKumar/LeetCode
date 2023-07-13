class Solution 
{
private:
    unordered_set<string> uset;
    
    unordered_map<int,unordered_map<string,bool>> umap; //umap[index][str]
    
    bool wordBreakUtil(string& s,int index,string str)
    {
        if(index==s.length()-1)
        {
            return uset.count(str+s[index]);
        }
        
        if(umap.count(index) && umap[index].count(str))
        {
            return umap[index][str];
        }
        
        bool notBreak=wordBreakUtil(s,index+1,str+s[index]);
        if(notBreak)
        {
            // return true;
            
            return umap[index][str]=true;
        }
        
        bool Break=false;
        if(uset.count(str+s[index]))
        {
            Break=wordBreakUtil(s,index+1,"");
        }
        
        // return Break; //Recursive Solution
        //TC: O(2^n) //as for every index (notBreak,Break) Recursion calls
        //SC: O(n)+O(n*k)auxiliary stack space
        
        return umap[index][str]=Break; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*n) //as for every index for every substring Recursion calls Memoized
        //SC: O(n*n)+O(n*k)auxiliary stack space
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        for(auto x:wordDict)
        {
            uset.insert(x);
        }
        
        return wordBreakUtil(s,0,"");
    }
};