class Solution 
{
public:
    double average(vector<int>& salary) 
    {
        long long sum=0;
        int n=salary.size()-2;
        int minim=salary[0];
        int maxim=salary[0];
        
        for(auto x:salary)
        {
            sum=sum+x;
            minim=min(minim,x);
            maxim=max(maxim,x);
        }
        
        sum=sum-minim-maxim;
        
        return (double)((sum)/(n*1.0));
    }
};