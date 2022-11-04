class Solution {
public:
    string reverseVowels(string s) 
    {
        unordered_set<char> set({'a','A','e','E','i','I','o','O','u','U'});
        int n=s.length();
        
        // string str;
        int j=n-1;
        for(int i=0; i<j; i++)
        {
            if(set.count(s[i]))
            {
                while(!set.count(s[j]) && j>i)
                {
                    j--;
                }
                
                char x=s[i];
                s[i]=s[j];
                s[j]=x;
                j--;
            }
        }
        
        return s;
    }
};