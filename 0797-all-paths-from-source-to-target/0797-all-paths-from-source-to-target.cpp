class Solution 
{
private:
    void pathsHelper(vector<vector<int>>& graph,int source,int target,vector<int>& vec,vector<vector<int>>& res)
    {
        if(source==target)
        {
            res.push_back(vec);
            return;
        }
        
        // vec.push_back(source);
        
        for(int i=0; i<graph[source].size(); i++)
        {
            vec.push_back(graph[source][i]);
            pathsHelper(graph,graph[source][i],target,vec,res);
            vec.pop_back();
        }
        
        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> res;
        vector<int> vec;
        
        vec.push_back(0);
        
        pathsHelper(graph,0,graph.size()-1,vec,res);
        
        return res;
    }
};