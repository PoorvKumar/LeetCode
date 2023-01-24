class Solution 
{
private:
    int n;
    
    pair<int,int> findCoordinates(int pos)
    {
        int r=n-(pos-1)/n-1;
        int c=(pos-1)%n;
        
        if(r%2==n%2)
        {
            c=n-1-c;
        }
        
        return make_pair(r,c);
    }
public:
    int snakesAndLadders(vector<vector<int>>& board)
    {
        n=board.size();
        
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        queue<int> q;
        q.push(1);
        
        visited[n-1][0]=true;
        
        int ans=0;
        
        
        while(!q.empty())
        {
            int s=q.size();
            
            for(int i=0; i<s; i++)
            {
                int x=q.front();
                q.pop();
                
                if(x==n*n)
                {
                    return ans;
                }
                
                for(int k=1; k<=6; k++)
                {
                    if(x+k>n*n)
                    {
                        break;
                    }
                    
                    pair<int,int> p=findCoordinates(x+k);
                    
                    if(visited[p.first][p.second])
                    {
                        continue;
                    }
                    
                    visited[p.first][p.second]=true;
                    
                    if(board[p.first][p.second]!=-1)
                    {
                        q.push(board[p.first][p.second]);
                    }
                    else
                    {
                        q.push(x+k);
                    }
                }
            }
            
            ans++;
        }
        
        return -1; //saw the solution in discuss section so need to practise and revise regulary as tricks like findCoordinates() function did not come before and did not think of BFS solution
    }
};