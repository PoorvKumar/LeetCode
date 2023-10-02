class Solution 
{
public:
    bool winnerOfGame(string s) 
    {
        int alice=0;
        int bob=0;
        
        for(int i=0; i<s.length(); i++)
        {
            int j=i+1;
            while(j<s.length() && s[i]==s[j])
            {
                j++;
            }
            
            int n=j-i;
            if(n>=3)
            {
                if(s[i]=='A')
                {
                    alice=alice+n-2;
                }
                else
                {
                    bob=bob+n-2;
                }
            }
            
            i=j-1;
        }
        
        return alice>bob;
    }
};