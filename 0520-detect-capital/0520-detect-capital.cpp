class Solution 
{
public:
    bool detectCapitalUse(string word) 
    {
        if(word.length()==1)
        {
            return true;
        }
        
        int i=0;
        bool flag;
        
        if(word[0]>=65 && word[0]<=90)
        {
            flag=word[1]>=65 && word[1]<=90;
            i=2;
        }
        else
        {
            flag=false;
            i++;
        }
        
        for( ; i<word.length(); i++) //A - Z -> 65 - 90 && a - z -> 97 - 122
        {
            if(flag) //all upper case
            {
                if(word[i]>90)
                {
                    return false;
                }
            }
            else // lower case from index 1  
            {
                if(word[i]<=90)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};