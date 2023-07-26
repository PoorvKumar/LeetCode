class Solution 
{
private:
    bool possibleSpeed(vector<int>& dist,int speed,double hour)
    {
        double val=0;
        
        for(int i=0; i<dist.size()-1; i++)
        {
            val=val+ceil(dist[i]/(speed*1.0));
        }
        
        val=val+dist.back()/(speed*1.0);
        
        return val<=hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        // long long s=accumulate(dist.begin(),dist.end(),0);
        long long s=0;
        
        int low=ceil(s/(hour*1.0));
        int high=1e9;
        
        int mid=(low+high)/2;
        
        while(low<high)
        {
            if(possibleSpeed(dist,mid,hour))
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
            mid=(low+high)/2;
        }
        
        return possibleSpeed(dist,mid,hour)?mid:-1;
    }
};