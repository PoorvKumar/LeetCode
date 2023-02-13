class Solution 
{
private:
    bool isPalindrome(string& s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
public:
    string longestPalindrome(string s) 
    {
        string str=s.substr(0,1);
        
        int n=s.length();
        
        for(int i=0; i<n; i++) //O(n^3) with some optimisation
        {
            for(int j=n-1; j>i && j-i+1>str.length(); j--)
            {
                if(s[i]==s[j] && isPalindrome(s,i,j))
                {
                    if(j-i+1>str.length())
                    {
                        str=s.substr(i,j-i+1); //s.substr(start_index,numbe_of_characters);
                        break;
                    }
                }
            }
        }
        
        return str;
    }
};