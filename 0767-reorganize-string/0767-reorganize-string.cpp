class Solution 
{
public:
    string reorganizeString(string s) 
    {
        unordered_map<char,int> umap;
        
        for(auto c:s)
        {
            umap[c]++;
        }
        
        priority_queue<pair<int,char>> pq;
        
        for(auto x:umap)
        {
            pq.push({x.second,x.first});
        }
        
        string str="";
        
        while(!pq.empty())
        {
            if(!str.empty() && str.back()==pq.top().second)
            {
                pair<int,char> p=pq.top();
                pq.pop();
                
                if(pq.empty())
                {
                    return "";
                }
                
                pair<int,char> q=pq.top();
                pq.pop();
                str=str+q.second;
                q.first--;
                if(q.first)
                {
                    // pq.push({q.first,q.second});
                    pq.push(q);
                }
                
                pq.push(p);
            }
            
            pair<int,char> p=pq.top();
            pq.pop();
            
            str=str+p.second;
            p.first--;
            
            if(p.first)
            {
                pq.push(p);
            }
        }
        
        return str;
    }
};