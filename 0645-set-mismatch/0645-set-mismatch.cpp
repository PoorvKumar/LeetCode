class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        vector<int> vec;
        
        vector<int> hash(nums.size()+1,0);
        
        for(int i=0; i<nums.size(); i++)
        {
            hash[nums[i]]++;
        }
        
        vector<int>::iterator it;
        it=find(hash.begin()+1,hash.end(),2);
        
        vec.push_back(it-hash.begin());
        
        it=find(hash.begin()+1,hash.end(),0);
        
        vec.push_back(it-hash.begin());
        
//         for(int i=1; i<hash.size(); i++)
//         {
//             if(hash[i]==2)
//             {
//                 vec.push_back(i);
//                 break;
//             }
//         }
        
//         for(int i=1; i<hash.size(); i++)
//         {
//             if(hash[i]==0)
//             {
//                 vec.push_back(i);
//                 break;
//             }
//         }
        
        return vec;
    }
};