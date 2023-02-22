class Solution 
{
private:
    bool check(vector<int>& weights,int days,int capacity)
    {
        int sum=0;
        int ships=1;
        
        for(int i=0; i<weights.size(); i++)
        {
            if(sum+weights[i]>capacity) //important
            {
                ships++;
                sum=0;
            }
            sum=sum+weights[i]; //imporant
        }
        
        if(ships>days)
        {
            return false;
        }
        
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days)
    {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        
        // cout<<low<<" "<<high<<endl;
        
        int mid=(low+high)/2;
        int ans=mid;
        
        while(low<=high)
        {
            mid=(low+high)/2;
            
            if(check(weights,days,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
    }
};