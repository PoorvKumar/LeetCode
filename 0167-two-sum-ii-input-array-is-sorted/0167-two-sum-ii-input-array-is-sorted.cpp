class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        for(int i=0; i<numbers.size()-1; i++)
        {
            auto it=upper_bound(numbers.begin()+i+1,numbers.end(),target-numbers[i]);
            it=prev(it);
            
            if(*it==target-numbers[i])
            {
                // int j=it-numbers.begin();
                int j=it-begin(numbers);
                
                return vector<int>({i+1,j+1});
            }
        }
        
        return vector<int>();
    }
};