class Solution 
{
private:
    bool isPalindrome(string& str)
    {
        int i=0;
        int j=str.length()-1;
        
        while(i<j)
        {
            if(str[i]!=str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) 
    {
        for(auto x:words)
        {
            if(isPalindrome(x))
            {
                return x;
            }
        }
        
        return "";
    }
};