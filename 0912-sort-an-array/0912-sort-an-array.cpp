class Solution 
{
private:
    int partition(vector<int>& nums,int low,int high)
    {
        int pivot=nums[high];
        
        int i=low-1;
        
        for(int j=low; j<high; j++)
        {
            if(nums[j]<pivot)
            {
                i++;
                swap(nums[i],nums[j]);
            }
        }
        
        swap(nums[i+1],nums[high]);
        
        return i+1;
    }
    
    void quickSort(vector<int>& nums,int low,int high)
    {
        if(low<high)
        {
            int x=partition(nums,low,high); //partition when last index as pivot
            quickSort(nums,low,x-1);
            quickSort(nums,x+1,high);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums)
    {
        // sort(nums.begin(),nums.end());
        
        // quickSort(nums,0,nums.size()-1);
        
        multiset<int> st(nums.begin(),nums.end());
        nums.assign(st.begin(),st.end());
        
        return nums;
    }
};