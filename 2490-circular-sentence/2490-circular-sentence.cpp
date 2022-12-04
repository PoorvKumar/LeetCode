class Solution {
public:
    bool isCircularSentence(string sentence) 
    {
        int i=0;
        int j=sentence.length()-1;
        
        if(sentence[i]!=sentence[j])
        {
            return false;
        }
        while(i<sentence.length() && sentence[i]!=' ')
        {
            i++;
        }
        j=i+1;
        i--;
        
        for( ; j<sentence.length(); j++)
        {
            if(sentence[i]!=sentence[j])
            {
                // cout<<sentence[i]<<" "<<sentence[j]<<endl;
                return false;
            }
            i=j;
            while(i<sentence.length() && sentence[i]!=' ')
            {
                i++;
            }
            j=i;
            i--;
        }
        
        return true;
    }
};