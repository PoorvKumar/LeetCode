class Solution {
public:
    string addBinary(string a, string b) 
    {
        string s;
        
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        int x=a.length();
        int y=b.length();
        
        int n=min(x,y);
        
        int i=0;
        int sum=0;
        int c=0;
        
        while(i<n)
        {
            int p=a[i]-'0';
            int q=b[i]-'0';
            i++;
            
            if(p+q+c==3)
            {
                sum=1;
                c=1;
            }
            else if(p+q+c==2)
            {
                sum=0;
                c=1;
            }
            else
            {
                sum=p+q+c;
                c=0;
            }
            s=s+to_string(sum);
        }
        
        n=max(x,y);
        while(i<n && i<x)
        {
            int p=a[i]-'0';
            i++;
            
            if(p+c==2)
            {
                sum=0;
                c=1;
            }
            else
            {
                sum=p+c;
                c=0;
            }
            
            s=s+to_string(sum);
        }
        
        while(i<n && i<y)
        {
            int q=b[i]-'0';
            i++;
            
            if(q+c==2)
            {
                sum=0;
                c=1;
            }
            else
            {
                sum=q+c;
                c=0;
            }
            
            s=s+to_string(sum);
        }
        
        if(c==1)
        {
            s=s+to_string(c);
        }
        
        reverse(s.begin(),s.end());
        
        return s;
    }
};