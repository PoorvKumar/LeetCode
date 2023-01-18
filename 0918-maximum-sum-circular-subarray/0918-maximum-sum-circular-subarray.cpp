class Solution 
{
private:
//     int maxSubArraySum(vector<int>& nums,int j) //Kadane's Algorithm
//     {
//         int n=nums.size();
       
//         int fsum=0;
//         // int bsum=0;
//         int fmaxim=nums[j];
//         // int bmaxim=nums[j];

//         int f=j;
//         // int b=j;

//         do
//         {
//             //forward
//             fsum=fsum+nums[f];
//             fmaxim=max(fmaxim,fsum);
//             if(fsum<0)
//             {
//                 fsum=0;
//             }
//             f=(f+1)%n;

//             // //backward
//             // bsum=bsum+nums[b];
//             // bmaxim=max(bmaxim,bsum);
//             // if(bsum<0)
//             // {
//             //     bsum=0;
//             // }
//             // b=(b-1+n)%n;
//         }
//         while(f!=j);
    
//         // return max(fmaxim,bmaxim);
//         return fmaxim;
//     }
    
    int maxSubArraySum(vector<int>& nums)
    {
        int sum=0;
        int maxim=nums[0];
        
        for(int i=0; i<nums.size(); i++)
        {
            sum=sum+nums[i];
            maxim=max(maxim,sum);
            if(sum<0)
            {
                sum=0;
            }
        }
        
        return maxim;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int n=nums.size();
        
        int maxim=nums[0];
        // for(int i=0; i<n; i++) //getting TLE //99 out of 111 testcases passed
        // {
        //     maxim=max(maxim,maxSubArraySum(nums,i));
        // }
        
//         return maxim;
        
        maxim=max(maxim,maxSubArraySum(nums));
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        int minim=nums[0];
        
        for(auto &x:nums)
        {
            x=x*-1;
        }
        
        // minim=min(minim,maxSubArraySum(nums,0)*-1);
        minim=maxSubArraySum(nums)*-1;
        
        if(sum-minim!=0)
        {
            maxim=max(maxim,sum-minim);
        }
        
        return maxim;
        
//         nums.insert(nums.end(),nums.begin(),nums.end()); //[-5,3,5] -> [-5,3,5,-5,3,5]
        
//         int sum=0;
//         maxim=nums[0];
        
//         // maxim=max(maxim,maxSubArraySum(nums,0,n));
        
//         for(int i=0; i<n; i++)  //giving TLE //102 of 111 testcases passed
//         {
//             sum=0;
//             maxim=max(maxim,nums[i]);
            
//             for(int j=i; j<i+n; j++)
//             {
//                 sum=sum+nums[j];
//                 maxim=max(maxim,sum);
//                 if(sum<0)
//                 {
//                     sum=0;
//                 }
//             }
//         }
        
        return maxim;
    }
};