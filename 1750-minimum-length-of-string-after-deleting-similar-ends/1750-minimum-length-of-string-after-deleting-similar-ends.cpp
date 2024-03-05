class Solution 
{
public:
    int minimumLength(string s) 
    {
        int left=0;
        int right=s.length()-1;
        
        while(left<right && s[left]==s[right])
        {
            if(right-left==1)
            {
                return 0;
            }
            
            int i=0;
            while(left+i<right && s[left]==s[left+i])
            {
                i++;
            }
            
            if(left+i==right)
            {
                return 0;
            }
            
            int j=0;
            while(right-j>left+i && s[right]==s[right-j])
            {
                j++;
            }
            
            left+=i;
            right-=j;
        }
        
        return right-left+1;
    }
};