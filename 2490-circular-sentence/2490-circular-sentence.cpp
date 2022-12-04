class Solution {
public:
    bool isCircularSentence(string sentence) 
    {
//         int i=0;
//         int j=sentence.length()-1;
        
//         while(i<sentence.length() && sentence[i]!=' ')
//         {
//             i++;
//         }
//         j=i+1;
//         i--;
        
//         for( ; j<sentence.length(); j++)
//         {
//             if(sentence[i]!=sentence[j])
//             {
//                 // cout<<sentence[i]<<" "<<sentence[j]<<endl;
//                 return false;
//             }
//             i=j;
//             while(i<sentence.length() && sentence[i]!=' ')
//             {
//                 i++;
//             }
//             j=i;
//             i--;
//         }
        
        int n=sentence.length();
        
        for(int i=0; i<n; i++)
        {
            if(sentence[i]==' ' && sentence[i-1]!=sentence[i+1])
            {
                return false;
            }
        }
        
        return sentence[0]==sentence[n-1];
    }
};