class Solution 
{
private:
    int gcd(int b,int a)
    {
        return a==0?b:gcd(a,b%a);
    }
    
    bool isGCD(string& s1,string& s2,string& x)
    {
        if(gcd(s1.length(),s2.length())!=x.length())
        {
            return false;
        }
        
        int i=0;
        int j=0;
        
        while(j<s1.length())
        {
            if(i>=x.length())
            {
                i=0;
            }
            
            if(x[i]!=s1[j])
            {
                return false;
            }
            if(j<s2.length() && x[i]!=s2[j])
            {
                return false;
            }
            
            j++;
            i++;
        }
        
        return true;
    }
public:
    string gcdOfStrings(string& str1, string& str2) 
    {
        if(str1.length()<str2.length())
        {
            str1.swap(str2);
        }
        
        for(int i=0; i<str2.length(); i++)
        {
            string x=str2.substr(0,i+1);
            
            if(isGCD(str1,str2,x))
            {
                return  x;
                // return gcdOfStrings(str1,x);
            }
        }
        
        return "";
    }
};