class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        set<char> setChar(sentence.begin(),sentence.end());
        
        return setChar.size()==26;
    }
};