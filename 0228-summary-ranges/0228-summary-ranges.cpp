class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> res;
        vector<long long> vec;
        
        if(nums.empty())
        {
            return res;
        }
        
        vec.push_back(nums[0]);
        
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]-vec.back()!=1)
            {
                if(vec.size()==1)
                {
                    string str=to_string(vec[0]);
                    res.push_back(str);
                }
                else
                {
                    string str=to_string(vec.front());
                    str=str+"->";
                    str=str+to_string(vec.back());
                    res.push_back(str);
                }
                vec.clear();
                // vec.push_back(nums[i]);
                // continue;
            }
            vec.push_back(nums[i]);
        }
        
        if(vec.size()==1)
        {
            string str=to_string(vec[0]);
            res.push_back(str);
        }
        else if(vec.size()>1)
        {
            string str=to_string(vec.front());
            str=str+"->";
            str=str+to_string(vec.back());
            res.push_back(str);
        }
        
        return res;
        
//         auto it=nums.begin();
//         advance(it,1);
        
//         for( ; it!=nums.end(); it++)
//         {
//             if(*it-vec.back()!=1)
//             {
//                 if(vec.size()==1)
//                 {
//                     string str=to_string(vec[0]);
//                     res.push_back(str);
//                 }
//                 else
//                 {
//                     string str=to_string(vec.front());
//                     str=str+"->";
//                     str=str+to_string(vec.back());
//                     res.push_back(str);
//                 }
//                 vec.clear();
//                 vec.push_back(*it);
//             }
//             vec.push_back(*it);  
//         }
    }
};