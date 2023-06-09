class Solution 
{
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        // char res=letters[0];
        
        for(auto c:letters)
        {
            if(c>target)
            {
                return c;
            }
        }
        
        return letters[0];
    }
};