class Solution 
{
private:
    bool isVowel(char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
public:
    int maxVowels(string s, int k)
    {
        int ans=0;
        int maxim=0;
        
        for(int i=0; i<k; i++)
        {
            if(isVowel(s[i]))
            {
                ans++;
            }
        }
        
        maxim=max(ans,maxim);
        
        int index=k;
        
        while(index<s.length())
        {
            if(isVowel(s[index-k]))
            {
                ans--;
            }
            
            if(isVowel(s[index]))
            {
                ans++;
            }
            
            maxim=max(maxim,ans);
            index++;
        }
        
        return maxim;
    }
};