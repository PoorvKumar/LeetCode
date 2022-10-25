class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string str1;
        str1="";
        
        string str2;
        str2="";
        
        for(auto x:word1)
        {
            // str1=str1+x;
            str1+=x;
        }
        
        for(int i=0; i<word2.size(); i++)
        {
            // str2=str2+word2[i];
            str2+=word2[i];
        }
        
        return str1.compare(str2)==0;
    }
};