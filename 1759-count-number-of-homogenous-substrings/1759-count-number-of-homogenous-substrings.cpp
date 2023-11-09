class Solution 
{
private:
    unsigned long long M=1e9+7;
public:
    int countHomogenous(string s) 
    {
        int ans=0;
        
        for(int i=0; i<s.length(); i++)
        {
            int j=i+1;
            while(j<s.length() && s[i]==s[j])
            {
                j++;
            }
            
            long long val=j-i;
            long long k=(val%M*(val+1)%M)%M/2;
            ans=ans+k%M;
            i=j-1;
        }
        
        return ans;
    }
};