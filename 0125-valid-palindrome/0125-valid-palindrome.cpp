class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        int i=0;
        int j=s.length()-1;
        
        int n=s.length();
        
        for(int i=0; i<j; i++,j--) //O(n)
        {
            if(s[i]>=65 && s[i]<=90)
            {
                s[i]=s[i]+32;
            }
            if(s[j]>=65 && s[j]<=90)
            {
                s[j]=s[j]+32;
            }
            
            while(i<j && (s[i]>90 && s[i]<97 || s[i]>122 || s[i]<48 || s[i]>57 && s[i]<65))
            {
                // s[i]=' ';
                i++;
            }
            while(i<j && (s[j]>90 && s[j]<97 || s[j]>122 || s[j]<48 || s[j]>57 && s[j]<65))
            {
                // s[j]=' ';
                j--;
            }
            
            if(i<j && s[i]>=65 && s[i]<=90)
            {
                s[i]=s[i]+32;
            }
            if(i<j && s[j]>=65 && s[j]<=90)
            {
                s[j]=s[j]+32;
            }
            
            if(i<j && s[i]!=s[j])
            {
                // cout<<(int)s[j]<<endl;
                return false;
            }
        }
        
        return true;
    }
};