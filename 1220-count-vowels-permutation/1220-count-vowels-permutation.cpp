class Solution 
{
private:
    unsigned long long M=1e9+7;
    // unordered_map<char,unordered_map<int,int>> umap; //umap[c][index]
    vector<vector<int>> dp;
    unordered_map<char,int> mp;
    
    int countVowels(int n,char c,int index)
    {
        if(index==n-1)
        {
            return 1;
        }
        
        // if(umap.count(c) && umap[c].count(index))
        // {
        //     return umap[c][index];
        // }
        
        if(dp[mp[c]][index]!=-1)
        {
            return dp[mp[c]][index];
        }
        
        int ans=0;
        
        switch(c)
        {
            case 'a':
                ans=countVowels(n,'e',index+1)%M;
                break;
            case 'e':
                ans=(countVowels(n,'a',index+1)%M+countVowels(n,'i',index+1)%M)%M;
                break;
            case 'i':
                ans=(countVowels(n,'a',index+1)%M+countVowels(n,'e',index+1)%M+countVowels(n,'o',index+1)%M+countVowels(n,'u',index+1)%M)%M;
                break;
            case 'o':
                ans=(countVowels(n,'i',index+1)%M+countVowels(n,'u',index+1)%M)%M;
                break;
            case 'u':
                ans=countVowels(n,'a',index+1)%M;
                break;
        }
        
        // return ans%M;
        
        // return umap[c][index]=ans%M;
        return dp[mp[c]][index]=ans%M;
    }
public:
    int countVowelPermutation(int n) 
    {
        vector<char> vec={'a','e','i','o','u'};
        
        dp.assign(5,vector<int>(n,-1));
        int i=0;
        for(auto c:vec)
        {
            mp[c]=i++;
        }
        
        int ans=0;
        for(auto c:vec)
        {
            ans=(ans%M+countVowels(n,c,0)%M)%M;
        }
        
        // vector<vector<int>> dp(5,vector<int>(n,-1));
        
        return ans%M;
    }
};