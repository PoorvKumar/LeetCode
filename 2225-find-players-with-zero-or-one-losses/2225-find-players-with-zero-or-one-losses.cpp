class Solution 
{
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        unordered_set<int> uset;
        unordered_map<int,int> lmap;
        vector<vector<int>> vec(2);
        
        for(int i=0; i<matches.size(); i++)
        {
            uset.insert(matches[i][0]);
            uset.insert(matches[i][1]);
            
            lmap[matches[i][1]]++;
        }
        
        for(auto x:uset)
        {
            if(!lmap.count(x))
            {
                vec[0].push_back(x);
            }
            else if(lmap[x]==1)
            {
                vec[1].push_back(x);
            }
        }
        
        sort(vec[0].begin(),vec[0].end());
        sort(vec[1].begin(),vec[1].end());
        
        return vec;
    }
};