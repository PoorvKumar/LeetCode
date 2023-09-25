class Solution 
{
public:
    char findTheDifference(string s, string t) 
    {
        return accumulate(t.begin(),t.end(),0)-accumulate(begin(s),end(s),0);
    }
};