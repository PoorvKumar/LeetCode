class Solution 
{
private:
    bool check(vector<int>& time,long long int t,int totalTrips)
    {
        long long sum=0;
        
        for(auto x:time) //TC: O(n)
        {
            sum=sum+t/x;
        }
        
        return sum>=totalTrips;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips)
    {
        long long low=0;
        long long high=0;
        long long mid=0;
        
        low=*min_element(time.begin(),time.end());
//         int maxim=*max_element(time.begin(),time.end());
        
//         for(auto x:time)
//         {
//             high=high+(maxim/x)*x;
//         }
        
//         if(high<totalTrips)
//         {
//             high=high+(totalTrips/low)*high; //after seeing test case //[66] 8295
//         }
        
        high=1e14; //to keep search space big enough when totalTrips>high calculated above
        
        mid=(low+high)/2;
        
        while(low<high) //TC: O(n*log(time)) //time=accumlate(time.begin(),time.end());
        {
            // mid=(low+high)/2;
            if(check(time,mid,totalTrips))
            {
                high=mid; //reducing search space to left side to find minimum time
            }
            else
            {
                low=mid+1; //reducing search space to right side as current t not enough for total trips
            }
            mid=(low+high)/2;
        }
        
        // cout<<low<<" "<<high<<endl;
        return mid;
    }
};