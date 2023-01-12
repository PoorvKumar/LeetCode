class Solution 
{
private:
    unordered_map<int,vector<int>> adjList;
    // vector<vector<int>> adjList;
    
    //     int countSubTreeUtil(int src,string labels,char x,int parent) //getting TLE
//     {
//         if(labels[src]==x)
//         {
//             labels[src]='-';
//             int y=countSubTreeUtil(src,labels,x,parent);
//             // int y=countSubTreeUtil(src,labels,x,visited);
//             // labels[src]=x;
//             return y+1;
//         }
        
//         int countLabel=0;
        
//         for(int i=0; i<adjList[src].size(); i++)
//         {
//             if(adjList[src][i]!=parent)
//             {
//                 int y=countSubTreeUtil(adjList[src][i],labels,x,src);
//                 countLabel=countLabel+y;
//             }
//             // if(!visited[adjList[src][i]])
//             // {
//             //     visited[adjList[src][i]]=true;
//             //     int y=countSubTreeUtil(adjList[src][i],labels,x,visited);
//             //     countLabel=countLabel+y;
//             // }
//         }
        
//         return countLabel;
//     }
    
    unordered_map<char,int> helper(int src,string& labels,vector<int>& ans)
    {
        // if(adjList[src].size()==1) //-1 added at 0 so that adjacency list of 0 always have atleast 2 elements
        // {
        //     // ans[src]=1;
        //     unordered_map<char,int> umap;
        //     umap[labels[src]]=1;
        //     return umap;
        // }
        
        unordered_map<char,int> countHash;
        countHash[labels[src]]=1;
        
        // int i=src==0?0:1;
        int i=1;
        
        for( ; i<adjList[src].size(); i++) //parent at 0 index
        {
            unordered_map<char,int> umap=helper(adjList[src][i],labels,ans);
            for(auto y:umap) //problem here is traversing through object of type class unordered_map everytime
            {
                countHash[y.first]=countHash[y.first]+y.second;
            }
        }
        
        ans[src]=1+countHash[labels[src]];
        countHash[labels[src]]=ans[src];
        return countHash;
    }
    
    void subTreeUtil(int src,string& labels,vector<int>& ans,vector<int>& countHash) //faster
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
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) //very very important to look submission notes
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
        
        vector<int> countHash(26,0);
        subTreeUtil(0,labels,ans,countHash);
        // countHelper(0,labels,ans);
        
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