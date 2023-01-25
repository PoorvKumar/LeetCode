class Solution 
{
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        // if(node1==node2) //below code deals with such cycles also //very verry cool
        // {
        //     return node1;
        // }
        
        vector<bool> visited(edges.size(),false);
        
        vector<int> vec1(edges.size(),INT_MAX);
        vec1[node1]=0;
        
        int n1=node1;
        while(n1!=-1 && !visited[n1])
        {
            visited[n1]=true;
            if(edges[n1]!=-1)
            {
                vec1[edges[n1]]=min(vec1[edges[n1]],1+vec1[n1]); //so in caae of cycles value same
            }
            n1=edges[n1];
        }
        
        // for(auto x:vec1)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        // vec1[node1]=0; //in case of cycle it changes the minim distance from itself
        
        visited.assign(edges.size(),false);
        
        vector<int> vec2(edges.size(),INT_MAX);
        vec2[node2]=0;
        
        int n2=node2;
        while(n2!=-1 && !visited[n2])
        {
            visited[n2]=true;
            if(edges[n2]!=-1)
            {
                vec2[edges[n2]]=min(vec2[edges[n2]],1+vec2[n2]);
            }
            n2=edges[n2];
        }
        
        // for(auto x:vec2)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        // vec2[node2]=0;
        
        int minim=INT_MAX;
        int minimindex=INT_MAX;
        
//         map<int,int> mp; // 71 / 77 testcases passed
        
//         if(vec1[node2]>vec2[node1] || (vec1[node2]==vec2[node1] && vec1[node2]==INT_MAX)) //in case of cycle node1 comes after node2
//         {
//             for(int i=0; i<edges.size(); i++)
//             {
//                 mp[vec2[i]]=i;
//             }
            
//             for(auto x:mp)
//             {
//                 if(x.first<INT_MAX && minim>vec1[x.second])
//                 {
//                     minim=vec1[x.second];
//                     minimindex=x.second;
//                     // minimindex=min(minimindex,x.second);
//                 }
//             }
//             // for(auto x:mp)
//             // {
//             //     cout<<x.second<<" "<<x.first<<endl;
//             // }
//         }
//         else //in cycle node2 comes after node1
//         {
//             for(int i=0; i<edges.size(); i++)
//             {
//                 mp[vec1[i]]=i;
//             }
            
//             for(auto x:mp)
//             {
//                 if(x.first<INT_MAX && minim>vec2[x.second])
//                 {
//                     minim=vec2[x.second];
//                     minimindex=x.second;
//                     // minimindex=min(minimindex,x.second);
//                 }
//             }
//         }
        
//         return minimindex!=INT_MAX?minimindex:-1;
        minimindex=-1;
        
        for(int i=0; i<edges.size(); i++)
        {
            if(minim>max(vec1[i],vec2[i]))
            {
                minim=max(vec1[i],vec2[i]);
                minimindex=i;
            }
        }
        
        return minimindex;
    }
};