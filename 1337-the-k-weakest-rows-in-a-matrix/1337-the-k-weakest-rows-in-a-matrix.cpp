class Solution 
{
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<vector<int>> vec;
        
        for(int i=0; i<mat.size(); i++)
        {
            int sum=accumulate(mat[i].begin(),mat[i].end(),0);
            vec.push_back(vector<int>({sum,i}));
            // vec.push_back({sum,i});
        }
        
        sort(vec.begin(),vec.end());
        
        vector<int> res;
        
        for(int i=0; i<k; i++)
        {
            res.push_back(vec[i][1]);
        }
        
        return res;
    }
};