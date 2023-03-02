class Solution 
{
public:
    int compress(vector<char>& chars)
    {
        int k=0;
        for(int i=0; i<chars.size(); i++)
        {
            chars[k]=chars[i];
            
            int j=i+1;
            while(j<chars.size() && chars[j]==chars[i])
            {
                j++;
            }
            
            int val=j-i;
            if(val>1)
            {
                string str=to_string(val);
                for(auto c:str)
                {
                    chars[++k]=c;
                }
            }
            k++;
            i=j-1;
        }
        
        return k;
    }
};