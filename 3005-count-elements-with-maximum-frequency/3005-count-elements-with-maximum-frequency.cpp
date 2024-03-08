class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101,0);
        
        for(auto x:nums)
        {
            freq[x]++;
        }
        
        int maxim=0;
        for(int i=0; i<101; i++)
        {
            maxim=max(maxim,freq[i]);
        }
        
        int sum=0;
        for(int i=0; i<101; i++)
        {
            if(freq[i]==maxim)
            {
                sum+=maxim;
            }
        }
        
        return sum;
    }
};