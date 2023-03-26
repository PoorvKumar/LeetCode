// class Solution 
// {
// private:
//     vector<bool> visited;
//     queue<int> q;
    
//     int longestCycleUtil(int src,vector<int>& edges)
//     {
//         if(src==-1)
//         {
//             while(!q.empty())
//             {
//                 q.pop();
//             }
//             for(int i=0; i<visited.size(); i++)
//             {
//                 if(!visited[i])
//                 {
//                     return longestCycleUtil(i,edges);
//                 }
//             }
            
//             return -1;
//         }
        
//         if(visited[src])
//         {
//             int k=q.size();
//             while(!q.empty() && q.front()!=src)
//             {
//                 q.pop();
//                 k--;
//             }
            
//             if(q.empty())
//             {
//                 return -1;
//             }
//             while(!q.empty())
//             {
//                 q.pop();
//             }
//             for(int i=0; i<visited.size(); i++)
//             {
//                 if(!visited[i])
//                 {
//                     return max(k,longestCycleUtil(i,edges));
//                 }
//             }
//             return k;
//         }
        
//         visited[src]=true;
//         q.push(src);
//         return longestCycleUtil(edges[src],edges);
//     }
    
// public:
//     int longestCycle(vector<int>& edges) 
//     {
//         visited.assign(edges.size(),false);
        
//         return longestCycleUtil(0,edges);
//     }
// };
class Solution {
public:
    int answer = -1;

    void dfs(int node, vector<int>& edges, unordered_map<int, int>& dist, vector<bool>& visit) {
        visit[node] = true;
        int neighbor = edges[node];

        if (neighbor != -1 && !visit[neighbor]) {
            dist[neighbor] = dist[node] + 1;
            dfs(neighbor, edges, dist, visit);
        } else if (neighbor != -1 && dist.count(neighbor)) {
            answer = max(answer, dist[node] - dist[neighbor] + 1);
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                unordered_map<int, int> dist;
                dist[i] = 1;
                dfs(i, edges, dist, visit);
            }
        }
        return answer;
    }
};