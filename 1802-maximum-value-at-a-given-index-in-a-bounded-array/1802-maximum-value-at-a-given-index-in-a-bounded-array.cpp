class Solution 
{
private:
    bool maxValUtil(int n,int index,int val,int maxSum)
    {
        long long sum=0;
        long long fsum=(long long)(val)*(long long)(val+1)/2;
        
        int i=index;
        int lval=val;
        // while(i--)  //index-0 elements in left subarray
        // {
        //     if(lval-1>0)
        //     {
        //         sum=sum+--lval;
        //         continue;
        //     }
        //     sum=sum+1;
        // }
        if(val-index>0)
        {
            long long lsum=(long long)(val-index-1)*(long long)(val-index)/2;
            sum=sum+fsum-lsum;
        }
        else
        {
            sum=sum+fsum+index-val+1;
        }
        
//         i=index+1;
//         int rval=val;
//         while(i++<n) //n-index-1 elements in right subarray
//         {
//             if(rval-1>0)
//             {
//                 sum=sum+--rval;
//                 continue;
//             }
//             sum=sum+1;
//         }
        int count=n-index-1;
        if(val-count>0)
        {
            long long rsum=(long long)(val-count-1)*(long long)(val-count)/2;
            sum=sum+fsum-rsum;
        }
        else
        {
            sum=sum+fsum+count-val+1;
        }
        
        sum=sum-val;
        
        // cout<<sum<<endl;
        
        return sum<=maxSum;
    }
public:
    int maxValue(int n, int index, int maxSum) 
    {
        int low=1;
        int high=maxSum;
        int mid=(low+high)/2;
        
        while(low<high)
        {
            // cout<<low<<" "<<mid<<" "<<high<<endl;
            bool res=maxValUtil(n,index,mid,maxSum); //TC: O(n) reduced to O(1)
            
            if(res)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
            mid=(low+high)/2;
        }
        
        if(maxValUtil(n,index,mid,maxSum))
        {
            return mid;
        }
        
        return mid-1;
        //TC: O(logn)
        //SC: O(1)
    }
};