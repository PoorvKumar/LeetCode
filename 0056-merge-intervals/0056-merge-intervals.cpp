class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if(intervals.size()==1)
        {
            return intervals;
        }
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        for(int i=1; i<intervals.size(); i++)
        {
            if(res.back()[1]>=intervals[i][0])
            {
                int high=max(res.back()[1],intervals[i][1]);
                vector<int> vec={res.back()[0],high};
                res.pop_back();
                res.push_back(vec);
                continue;
            }
            
            res.push_back(intervals[i]);
        }
        
        return res;
    }
};