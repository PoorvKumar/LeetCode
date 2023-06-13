class Solution 
{
private:
    unordered_map<int,int> umap; //umap[index]
    
    bool isPalindrome(string& str)
    {
        int i=0;
        int j=str.length()-1;
        
        while(i<j)
        {
            if(str[i]!=str[j])
            {
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
    
    int minCutUtil(string& s,int index)
    {
        if(index>=s.length()-1)
        {
            return 0;
        }
        
        if(umap.count(index))
        {
            return umap[index];
        }
        
        int ans=s.length()-index-1;
        string str="";
        
        for(int i=index; i<s.length(); i++)
        {
            // str=str+s[i];
            str.push_back(s[i]);
            if(isPalindrome(str))
            {
                int val=minCutUtil(s,i+1);
                if(i+1<s.length())
                {
                    val=val+1;
                }
                ans=min(ans,val);
            }
        }
        
        // return ans; //Recursive Solution
        //TC: O(n*n) //as n Recursion call for every index
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[index]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*n) //as for evry index Recursion calls Memoized
        //SC: O(n)+O(n)auxiliary stack space
    }
public:
    int minCut(string s) 
    {
        return minCutUtil(s,0);
    }
};