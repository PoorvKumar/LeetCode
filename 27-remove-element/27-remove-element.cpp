class Solution {
private:
    void swap(int* x,int* y)
    {
        int tmp=*x;
        *x=*y;
        *y=tmp;
    }
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int k=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==val)
            {
                k++;
            }
        }
        
        if(k==nums.size())
        {
            return 0;
        }
        
        int i=0;
        int j=nums.size()-1;
        
        for( ; i<j; i++)
        {
            while(i<j && nums[j]==val)
            {
                j--;
            }
            
            if(nums[i]==val)
            {
                swap(&nums[i],&nums[j]);
            }
        }
        
        return nums.size()-k;
    }
};