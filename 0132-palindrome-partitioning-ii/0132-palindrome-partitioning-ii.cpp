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
            // str=str+s[i]; //giving TLE
            
            // str.push_back(s[i]); //works
            str+=s[i]; //works
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
        // return minCutUtil(s,0);
        
        int n=s.length();
        vector<int> dp(n+1,0);
        
        for(int i=n-1; i>=0; i--)
        {
            int ans=s.length()-i-1;
            string str="";
            
            for(int j=i; j<s.length(); j++)
            {
                str+=s[j];
                // str.push_back(s[j]);
                
                if(isPalindrome(str))
                {
                    int val=dp[j+1];
                    if(j+1<n)
                    {
                        val=val+1;
                    }
                    
                    ans=min(ans,val);
                }
            }
            
            dp[i]=ans;
        }
        
        return dp[0]; //Bottom-Up DP approach -> Tabulation
        //TC: O(n*n)
        //SC: O(n)
    }
};