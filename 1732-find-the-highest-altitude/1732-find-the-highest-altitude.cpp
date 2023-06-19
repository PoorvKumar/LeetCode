class Solution 
{
public:
    int largestAltitude(vector<int>& gain) 
    {
        // vector<int> altitude(gain.size()+1,0);
        int maxim=0;
        int sum=0;
        
        for(int i=0; i<gain.size(); i++)
        {
            sum=sum+gain[i];
            maxim=max(maxim,sum);
            // altitude[i+1]=altitude[i]+gain[i];
            // maxim=max(maxim,altitude[i+1]);
        }
        
        return maxim;
    }
};