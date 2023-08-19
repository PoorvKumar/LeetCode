class Solution 
{
public:
    int kthFactor(int n, int k) 
    {
        vector<int> vec;
        
        for(int i=1; i<=n/2; i++)
        {
            if(n%i==0)
            {
                vec.push_back(i);
            }
        }
        
        vec.push_back(n);
        
        return k<=vec.size()?vec[k-1]:-1;
    }
};