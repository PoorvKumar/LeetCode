class Solution 
{
public:
    int minFlips(int a, int b, int c) 
    {
        bitset<32> bsA(a);
        bitset<32> bsB(b);
        
        string s0=bsA.to_string();
        string s1=bsB.to_string();
        
        string s2=bitset<32>(c).to_string(); //declared an object of type class bitset<32> by calling the parameterised constructor of class bitset and then called to_string() function over the object of rtype class bitset<32>
        
        bitset<32> bsC(c);
        
        int ans=0;
        
        for(int i=0; i<32; i++)
        {
            if(s2[i]=='0')
            {
                if(s0[i]=='1')
                {
                    ans++;
                }
                if(s1[i]=='1')
                {
                    ans++;
                }
            }
            else
            {
                if(s0[i]=='0' && s1[i]=='0')
                {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};