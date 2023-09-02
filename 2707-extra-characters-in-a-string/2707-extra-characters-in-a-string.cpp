class Solution 
{
private:
    unordered_set<string> uset;
    
    vector<vector<int>> dp;
    
    int minExtraCharUtil(string& s,int index,int last)
    {
        string str=s.substr(last,index-last);
        // cout<<str<<endl;
        
        if(index>=s.length())
        {
            if(!uset.count(str))
            {
                return str.length();
            }
            return 0;
        }
        
        if(dp[index][last]!=-1)
        {
            return dp[index][last];
        }
        
        int notBreak=minExtraCharUtil(s,index+1,last);
        int Break=minExtraCharUtil(s,index+1,index);
        
        if(!uset.count(str))
        {
            Break=Break+str.length();
        }
        
        // return min(notBreak,Break);
        
        return dp[index][last]=min(notBreak,Break);
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        for(auto &str:dictionary)
        {
            uset.insert(str);
        }
        
        if(s.length()==1)
        {
            return uset.count(s)!=1;
        }
        
        int n=s.length();
        
        dp.assign(n+1,vector<int>(n+1,-1));
        
        return minExtraCharUtil(s,1,0);
    }
};