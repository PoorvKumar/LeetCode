class Solution 
{
public:
    string maximumOddBinaryNumber(string s) 
    {
        int countOne=0;
        
        for(auto c:s)
        {
            if(c=='1')
            {
                countOne++;
            }
        }
        
        string res="";
        countOne--;
        
        while(res.length()<s.length()-1)
        {
            if(countOne>0)
            {
                res+='1';
                countOne--;
            }
            else
            {
                res+='0';
            }
        }
        
        res+='1';
        
        return res;
    }
};