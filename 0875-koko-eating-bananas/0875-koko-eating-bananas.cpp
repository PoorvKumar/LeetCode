class Solution 
{
private:
    int check(vector<int>& piles,int k,int h)
    {
        int count=0;
        for(auto x:piles)
        {
            // while(x>0)
            // {
            //     x=x-k;
            //     count++;
            // }
            count=count+x/k;
            if(x%k!=0)
            {
                count++;
            }
        }
        
        return count;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        
        int mid;
        mid=(low+high)/2;
        
        while(low<high) //TC: O(n*log(maxim))
        {
            int hours=check(piles,mid,h);
            
            if(hours<=h)
            {
                high=mid; //couunt<=h is true , to make count==h true 
                //we need to increase count by decreasing k 
                //by reducing search space to left side
                
            }
            else
            {
                low=mid+1; //count>h is true, to make count==h true 
                //we need to decrease count by increasing k
                //by reducing search space to right side
            }
            
            mid=(low+high)/2;
        }
        
        return mid;
    }
};