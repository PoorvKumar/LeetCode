class Solution 
{
private:
    unordered_map<int,vector<int>> adjList;
    // vector<vector<int>> adjList;
    
    void subTreeUtil(int src,string& labels,vector<int>& ans,vector<int>& countHash) 
    {
        // vector<int> countHash(26,0); 
        int prevCount=countHash[labels[src]-97];
        
        for(int i=1; i<adjList[src].size(); i++)
        {
            subTreeUtil(adjList[src][i],labels,ans,countHash);
        }
        
        countHash[labels[src]-97]++;
        ans[src]=countHash[labels[src]-97]-prevCount;
        return;
    }
    vector<int> countHelper(int src,string& labels,vector<int>& ans)
    {
        vector<int> countHash(26,0);
        countHash[labels[src]-97]++;
        
        for(int i=1; i<adjList[src].size(); i++)
        {
            vector<int> vec=countHelper(adjList[src][i],labels,ans);
            for(int j=0; j<26; j++)
            {
                countHash[j]=countHash[j]+vec[j];
            }
        }
        
        ans[src]=countHash[labels[src]-97];
        return countHash;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
    {
        // adjList.assign(n,vector<int>());
        adjList[0].push_back(-1); //parent at 0 index assigned -1 so i always starts from 1
        
        for(int i=0; i<edges.size(); i++) //adjacency list
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> ans(n,0);
        
        // for(auto x:adjList)
        // {
        //     cout<<x.first<<" -> ";
        //     for(auto y:x.second)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        // vector<int> countHash(26,0);
        // subTreeUtil(0,labels,ans,countHash);
        countHelper(0,labels,ans);
        
        return ans;
        
//         unordered_map<int,int> parent; //parent of all nodes
//         for(auto x:adjList)
//         {
//             parent[x.first]=x.second[0]; //parent of a node present at 0 index in its adjacency list as added first from edge list
//         }
//         parent[0]=-1;
        
//         // for(auto x:parent)
//         // {
//         //     cout<<x.first<<" -> "<<x.second<<endl;
//         // }
        
//         for(int i=0; i<n; i++)
//         {
//             countNodes.push_back(countSubTreeUtil(i,labels,labels[i],parent[i]));
//         }
        
//         return countNodes;
    }
};