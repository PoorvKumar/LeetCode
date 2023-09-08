class Solution 
{
private:
    vector<int> generateUtil(int n,vector<int>& last)
    {
        vector<int> vec(n,0);
        vec[0]=1;
        vec.back()=1;
        
        for(int i=1; i<n-1; i++)
        {
            vec[i]=last[i-1]+last[i];
        }
        
        return vec;
    }
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> res;
        res.push_back({1});
        
        if(numRows==1)
        {
            return res;
        }
        
        for(int i=2; i<=numRows; i++)
        {
            vector<int> vec=generateUtil(i,res.back());
            res.push_back(vec);
        }
        
        return res; 
        //TC: O(n^2)
        //SC: O(n^2)
    }
};