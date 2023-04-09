class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int m=nums1.size();
        int n=nums2.size();
        
        vector<int> nums;
        
        int i=0;
        int j=0;
        
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                nums.push_back(nums1[i]);
                i++;
            }
            else
            {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        
        if(i==m || j==n)
        {
            if(i==m)
            {
                while(j<n)
                {
                    nums.push_back(nums2[j++]);
                }
            }
            while(i<m)
            {
                nums.push_back(nums1[i++]);
            }
        }
        
        double ans=0;
        
        if((m+n)%2==0)
        {
            ans=(double)(nums[(m+n)/2]+nums[(m+n)/2-1])/2;
            return ans;
        }
        
        return (double)nums[(m+n)/2];
    }
};