class Solution 
{
private:
    unordered_map<int,vector<int>> indices;
    // unordered_map<int,vector<int>> adjList;
    int n;
    
    int bfs(vector<int>& arr,int src)
    {
        int ans=0;
        
        queue<int> q;
        vector<bool> visited(n,false);
        
        q.push(src);
        while(!q.empty())
        {
            int k=q.size();
            while(k--)
            {
                int curr=q.front();
                q.pop();
                
                visited[curr]=true;
                
                if(curr==n-1)
                {
                    return ans;
                }
                
                vector<int>& vec=indices[arr[curr]];
                
                vec.push_back(curr-1);
                vec.push_back(curr+1);
                
                for(auto node:vec)
                {
                    if(node>=0 && node<n && !visited[node])
                    {
                        q.push(node);
                        visited[node]=true;
                    }
                }
                
                vec.clear(); //need to reevise this problem
            }
            
            ans++;
        }
        
        return -1;
    }
    
public:
    int minJumps(vector<int>& arr)
    {
        if(arr.size()==1)
        {
            return 0;
        }
        
        if(arr.size()==2)
        {
            return 1;
        }
        
        n=arr.size();
        
        for(int i=0; i<arr.size(); i++)
        {
            indices[arr[i]].push_back(i);
        }
        
        return bfs(arr,0);
        
//         for(int i=0; i<arr.size(); i++) //TC: O(n^2) getting TLE again //SC: O(n^2)
//         {
//             if(i>0)
//             {
//                 adjList[i].push_back(i-1);
//             }
//             if(i<arr.size()-1)
//             {
//                 adjList[i].push_back(i+1);
//             }
            
//             for(auto j:indices[arr[i]])
//             {
//                 if(j!=i && j!=i-1 && j!=i+1)
//                 {
//                     adjList[i].push_back(j);
//                 }
//             }
//         }
        
        // for(auto x:adjList)
        // {
        //     cout<<x.first<<" -> ";
        //     for(auto y:x.second)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        // return dijkstraAlgo(0,arr.size()-1);
    }
};

