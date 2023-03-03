class Solution 
{
public:
    int strStr(string haystack, string needle)
    {
//         int ans=haystack.find(needle);
//         if(ans==haystack.length())
//         {
//             ans=-1;
//         }
        
//         return ans;
        
        for(int i=0; i<haystack.length(); i++)
        {
            if(i+needle.length()>haystack.length())
            {
                break;
            }
            
            if(haystack.substr(i,needle.length()).compare(needle)==0)
            {
                return i;
            }
        }
        
        return -1;
    }
};