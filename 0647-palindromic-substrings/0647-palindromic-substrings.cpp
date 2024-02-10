class Solution 
{
private:
    int countUtil(string& s,int left,int right,int index)
    {
        while(left>=0 && right<s.length() && s[left]==s[right])
        {
            left--;
            right++;
        }
        
        return right-index;
    }
public:
    int countSubstrings(string s) 
    {
        int ans=0;
        
        for(int i=0; i<s.length(); i++)
        {
            if(i>0 && s[i]==s[i-1])
            {
                ans+=countUtil(s,i-1,i,i);
            }
            ans=ans+countUtil(s,i,i,i);
        }
        
        return ans;
    }
};