class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        if(a.length()<b.length())
        {
            a.swap(b);
        }
        
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        int i=0;
        // int sum=0;
        int carry=0;
        
        while(i<a.length() && i<b.length())
        {
            if(a[i]==b[i])
            {
                if(a[i]=='1')
                {
                    if(carry==0)
                    {
                        carry=1;
                        a[i]='0';
                    }
                }
                else
                {
                    if(carry==1)
                    {
                        a[i]='1';
                        carry=0;
                    }
                }
            }
            else
            {
                if(carry==1)
                {
                    a[i]='0';
                }
                else
                {
                    a[i]='1';
                }
            }
            
            i++;
        }
        
        while(i<a.length())
        {
            if(carry==1)
            {
                if(a[i]=='1')
                {
                    a[i]='0';
                }
                else
                {
                    a[i]='1';
                    carry=0;
                    break;
                }
            }
            
            i++;
        }
        
        if(carry==1)
        {
            a.push_back('1');
        }
        
        reverse(a.begin(),a.end());
        
        return a;
    }
};