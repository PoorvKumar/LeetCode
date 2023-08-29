class Solution 
{
public:
    int bestClosingTime(string customers) 
    {
        int n=customers.size();
        
        vector<int> prefix(n,0);
        
        int N=0;
        
        for(int i=0; i<n; i++)
        {
            prefix[i]=N;
            if(customers[i]=='N')
            {
                N++;
            }
        }
        
        vector<int> suffix(n,0);
        
        int Y=0;
        
        for(int i=n-1; i>=0; i--)
        {
            if(customers[i]=='Y')
            {
                Y++;
            }
            suffix[i]=Y;
        }
        
        int minim=INT_MAX;
        int res=-1;
        
        for(int i=0; i<n; i++)
        {
            int val=prefix[i]+suffix[i];
            if(val<minim)
            {
                minim=val;
                res=i;
            }
        }
        
        if(prefix[n-1]<minim)
        {
            return n;
        }
        
        return res;
    }
};