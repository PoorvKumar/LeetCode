class Solution 
{
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        priority_queue<vector<int>> pq;
        
        for(int i=0; i<score.size(); i++)
        {
            pq.push({score[i],i});
        }
        
        vector<string> res(score.size());
        
        int rank=1;
        
        while(!pq.empty())
        {
            vector<int> vec=pq.top();
            pq.pop();
            
            string str="";
            
            switch(rank)
            {
                case 1:
                    str="Gold Medal";
                    break;
                case 2:
                    str="Silver Medal";
                    break;
                case 3:
                    str="Bronze Medal";
                    break;
                default:
                    str=to_string(rank);
            }
            
            res[vec[1]]=str;
            rank++;
        }
        
        return res;
    }
};