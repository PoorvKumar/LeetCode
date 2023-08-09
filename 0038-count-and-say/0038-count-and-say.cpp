class Solution 
{
private:
    string convert(string& str)
    {
        string s="";
        
        for(int i=0; i<str.length(); i++)
        {
            int j=i+1;
            while(j<str.length() && str[i]==str[j])
            {
                j++;
            }
            
            s+=to_string(j-i);
            s+=str[i];
            
            i=j-1;
        }
        
        return s;
    }
public:
    string countAndSay(int n) 
    {
        if(n==1)
        {
            return "1";
        }
        
        string str=countAndSay(n-1);
        str=convert(str);
        
        return str;
    }
};