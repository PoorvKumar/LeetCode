class KthLargest 
{
private:
    int k;
    vector<int> vec;
    int kthLargest;
public:
    KthLargest(int k, vector<int>& nums) 
    {
        this->k=k;
        
        if(nums.empty())
        {
            vec.push_back(INT_MIN);
            this->kthLargest=vec[0];
            
            return ;
        }
        
        sort(nums.begin(),nums.end(),greater<int>());
        
        int n=nums.size();
        k=min(n,k);
        
        while(k--)
        {
            vec.push_back(nums[k]);
        }
        
        this->kthLargest=vec[0];
    }
    
    int add(int val)
    {
        if(vec.size()<k)
        {
            vec.push_back(val);
            return kthLargest=*min_element(vec.begin(),vec.end());
        }
        
        // kthLargest=*min_element(vec.begin(),vec.end());
        
        if(val<=kthLargest)
        {
            return kthLargest;
        }
        
        vec.erase(min_element(vec.begin(),vec.end())); 
        vec.push_back(val);
        // sort(vec.begin(),vec.end());
        
        return kthLargest=*min_element(vec.begin(),vec.end());
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */