class Solution 
{
private:
    bool isVowel(char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
public:
    string sortVowels(string s) 
    {
        string vowels="";
        
        vector<int> vec;
        
        for(int i=0; i<s.length(); i++)
        {
            if(isVowel(s[i]))
            {
                vowels.push_back(s[i]);
                vec.push_back(i);
                // t[i]='_';
            }
            // else
            // {
            //     t[i]=s[i];
            // }
        }
        
        sort(vowels.begin(),end(vowels));
        
        int k=0;
        
        for(auto index:vec)
        {
            s[index]=vowels[k++];
        }
        
        return s;
    }
};