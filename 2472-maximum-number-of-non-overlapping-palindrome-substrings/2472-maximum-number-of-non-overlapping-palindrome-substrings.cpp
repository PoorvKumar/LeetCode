class Solution 
{
private:
    vector<int> dp;
    
    bool isPalindrome(string& str,int i,int j)
    {
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
    
    int maxPalindromesUtil(string& s,int k,int index)
    {
        if(index+k>s.length())
        {
            return 0;
        }
        
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        
        int exclude=maxPalindromesUtil(s,k,index+1);
        
        int i=index+k-1;
        while(i<s.length() && !isPalindrome(s,index,i))
        {
            i++;
        }
        
        int include=0;
        if(i<s.length())
        {
            include=1+maxPalindromesUtil(s,k,i+1);
        }
        
        // return max(exclude,include);
        return dp[index]=max(exclude,include);
    }
public:
    int maxPalindromes(string s, int k) 
    {
        dp.assign(s.length()+1,-1);
        
        return maxPalindromesUtil(s,k,0);
    }
};