class Solution 
{
public:
    bool halvesAreAlike(string s) 
    {
        unordered_set<char> uset({'a','A','i','I','e','E','o','O','u','U'});
        
        int countL=0;
        int countR=0;
        int j=s.length()/2;
        
        for(int i=0; i<s.length()/2; i++)
        {
            if(uset.count(s[i]))
            {
                countL++;
            }
            if(uset.count(s[j]))
            {
                countR++;
            }    
            j++;
        }
        
        // for(int i=0,j=s.length()/2; j<s.length(); i++,j++)
        // {
        //     if(uset.count(s[i]))
        //     {
        //         countL++;
        //     }
        //     if(uset.count(s[j]))
        //     {
        //         countR++;
        //     }
        // }
        
        return countL==countR;
    }
};