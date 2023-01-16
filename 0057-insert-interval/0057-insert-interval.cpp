class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        if(intervals.size()==0)
        {
            return vector<vector<int>>(1,newInterval);
        }
        
        vector<vector<int>> res;
        int start=newInterval[0];
        int end=newInterval[1];
        
        bool flag=false;
        
        for(int i=0; i<intervals.size(); i++)
        {
            start=intervals[i][0];
            end=intervals[i][1];
            
            if(!flag && newInterval[1]<start)
            {
                flag=true;
                res.push_back(newInterval);
            }
            
            if(!flag && end>=newInterval[0])
            {
                flag=true;
                start=min(start,newInterval[0]);
                end=max(end,newInterval[1]);
                while(i<intervals.size() && end>=intervals[i][1])
                {
                    i++;
                }
                if(i<intervals.size())
                {
                    if(intervals[i][0]<=end)
                    {
                        end=max(end,intervals[i][1]); //in case i not incremented
                        // res.push_back({start,end});
                        // i--;
                        // continue;
                    }
                    else
                    {
                        i--;
                    }
                }
            }
            res.push_back({start,end});
        }
        
        if(!flag)
        {
            res.push_back({newInterval[0],newInterval[1]});
        }
        
        return res;
    }
};