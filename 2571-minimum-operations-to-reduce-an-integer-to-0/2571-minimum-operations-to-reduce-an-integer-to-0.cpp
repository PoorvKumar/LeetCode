class Solution
{
private:
    vector<int> vec;
public:
    Solution()
    {
        for(int i=0; i<20; i++)
        {
            // vec[i]=pow(2,i); //2^10==1024 1024*1024<10^6
            vec.push_back(pow(2,i));
        }
    }
    
    int minOperations(int n)
    {
        if(n==0)
        {
            return 0;
        }
        
        int i=0;
        while(vec[i]<=n)
        {
            i++;
        }
        
        if(vec[i]-n>n-vec[i-1])
        {
            return 1+minOperations(n-vec[i-1]);
        }
        else
        {
            return 1+minOperations(vec[i]-n);
        }
    }
};