class Solution 
{
private:
    long long M=1e9+7;
    unordered_map<int,unordered_map<int,int>> umap;
    
    int numberOfArraysUtil(string& s,int left,int index,long long k)
    {
        if(s[left]=='0')
        {
            return 0;
        }
        
        long long val=stol(s.substr(left,index-left+1));
        if(val>k)
        {
            return 0;
        }
        
        if(index==s.length()-1)
        {
            return 1;
        }
        
        if(umap.count(left) && umap[left].count(index))
        {
            return umap[left][index];
        }
        
        int current=numberOfArraysUtil(s,left,index+1,k);
        int next=numberOfArraysUtil(s,index+1,index+1,k);
        
        // return (current+next)%M; //Recursive Solution
        //TC: O(2^n)
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[left][index]=(current+next)%M; //Top-Down DP apporach -> Recursion + Memoization
        //TC: O(n^2)
        //SC: O(n)+O(n)auxiliary stack space
    }
public:
    int numberOfArrays(string s, int k) 
    {
        return numberOfArraysUtil(s,0,0,k);
    }
};