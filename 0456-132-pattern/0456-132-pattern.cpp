class Solution 
{
private:
    bool findPatternUtil(vector<int>& nums,vector<int>& vec,int index)
    {
        if(vec.size()==3)
        {
            if(vec[1]>vec[0] && vec[1]>vec[2] && vec[2]>vec[0])
            {
                return true;
            }
            
            return false;
        }
        
        if(index>=nums.size())
        {
            return false;
        }
        
        bool ans=false;
        
        //exclude
        ans=findPatternUtil(nums,vec,index+1);
        if(ans)
        {
            return true;
        }
        
        //include
        vec.push_back(nums[index]);
        ans=findPatternUtil(nums,vec,index+1);
        vec.pop_back();
        
        return ans;
    }
public:
    bool find132pattern(vector<int>& nums) 
    {
//         vector<int> vec;
        
//         return findPatternUtil(nums,vec,0);
        
        int s3 = INT_MIN;
        stack<int> st;
        for( int i = nums.size()-1; i >= 0; i -- ){
            if( nums[i] < s3 ) return true;
            else while( !st.empty() && nums[i] > st.top() ){ 
              s3 = st.top(); st.pop(); 
            }
            st.push(nums[i]);
        }
        return false;

    }
};