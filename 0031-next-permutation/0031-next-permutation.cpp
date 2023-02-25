class Solution 
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int i=nums.size()-1;
        int j=i-1;
        
        while(j>=0 && nums[i]<=nums[j])
        {
            i--; //as decreasing from right to left
            j--;
        }
        
        if(j<0)
        {
            reverse(nums.begin(),nums.end()); //4 3 2 1
            return ;
        }
        
        int k=nums.size()-1;
        while(nums[k]<=nums[j])
        {
            k--; //just greater element from the element to be swapped
        }
        
        // swap(&nums[j],&nums[k]); //does not work
        swap(nums[j],nums[k]); //also works
        // int tmp=nums[k];
        // nums[k]=nums[j];
        // nums[j]=tmp;
        
        //sort() the remainning object nums of type class vector<int> 
        sort(nums.begin()+j+1,nums.end()); //[startAddress,endAddress) [beginIterator,endIterator)
        //contiguous memory allocation in an object of type class vector<int>
        
        return ;
    }
};