bool compare(string& s1,string& s2)
{
    return s1.length()<s2.length();
}

class Solution 
{
private:
    vector<vector<int>> dp;
    
    bool isValid(string& s1,string& s2)
    {
        if(s2.length()+1!=s1.length())
        {
            return false;
        }
        
        int diff=-1;
        
        int i=0;
        int j=0;
        while(i<s1.length() && j<s2.length())
        {
            if(s1[i]!=s2[j])
            {
                if(diff!=-1)
                {
                    return false;
                }
                diff=i;
                i++;
                continue;
            }
            i++;
            j++;
        }
        
        return true;
    }
    
    int longestChainUtil(vector<string>& words,int index,int last)
    {
        if(index>=words.size())
        {
            return 0;
        }
        
        if(dp[index][last+1]!=-1)
        {
            return dp[index][last+1];
        }
        
        int exclude=longestChainUtil(words,index+1,last);
        int include=0;
        
        if(last==-1 || isValid(words[index],words[last]))
        {
            include=1+longestChainUtil(words,index+1,index);
        }
        
        // return max(exclude,include); //Recursive Solution
        //TC: O(n*k*2^(n)) //as for every last 2(exclude,include) Recursion calls && index increases && isValid() takes O(k) worst case TC to check predecessor
        //SC: O(n*n)+O(n*n)auxiliary stack space
        
        return dp[index][last+1]=max(exclude,include); //Top-down DP approach -> Recursion + Memoization
        //TC: O(n*n*k) //as for every last for every index Recursion calls Memoized
        //SC: O(n*n)+O(n*n)auxiliary stack space
    }
public:
    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(),words.end(),compare);
        
        int n=words.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        
        return longestChainUtil(words,0,-1);
    }
};