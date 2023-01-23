class Solution 
{
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        if(n==1)
        {
            return 1;
        }
        
        unordered_map<int,unordered_set<int>> adjList;
        
        for(auto x:trust)
        {
            adjList[x[0]].insert(x[1]);
        }
        
        if(adjList.size()==0)
        {
            return -1;
        }
        
        for(int i=1; i<=n; i++)
        {
            if(adjList.count(i)==0)
            {
                bool flag=true;
                for(int j=1; j<=n; j++)
                {
                    if(i!=j)
                    {
                        if(adjList[j].count(i)==0)
                        {
                            return -1;
                        }
                    }
                }
                return i;
            }
        }
        
        return -1;
//         vector<vector<int>> adjList(n+1,vector<int>());
        
//         for(int i=0; i<trust.size(); i++)
//         {
//             int x=trust[i][0];
//             int y=trust[i][1];
//             adjList[x].push_back(y);
//         }
        
//         // for(auto x:adjList)
//         // {
//         //     // cout<<x.first<<" -> ";
//         //     for(auto y:x)
//         //     {
//         //         cout<<y<<" ";
//         //     }
//         //     cout<<endl;
//         // }
        
//         for(int i=1; i<=n; i++)
//         {
//             if(adjList[i].empty())
//             {
//                 bool flag=true;
//                 for(int j=1; j<=n; j++)
//                 {
//                     if(i!=j)
//                     {
//                         if(find(adjList[j].begin(),adjList[j].end(),i)==adjList[j].end())
//                         {
//                             return-1;
//                             // flag=false;
//                             // break;
//                         }
//                     }
//                 }
                
//                 return i;
//                 // return flag?i:-1;
//             }
//         }
        
//         return -1;
    }
};