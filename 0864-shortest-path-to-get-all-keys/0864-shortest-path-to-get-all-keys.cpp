class Solution 
{
private:
    int m;
    int n;
    
    unordered_set<char> uset;
    vector<vector<bool>> visited;
    
    int shortestPathUtil(vector<string>& grid,int i,int j,int k)
    {
        if(k==0)
        {
            return -1;
        }
        
        if(grid[i][j]=='#')
        {
            return INT_MAX;
        }
        
        if(isupper(grid[i][j]))
        {
            if(!uset.count(tolower(grid[i][j])))
            {
                return INT_MAX;
            }
        }
        
        if(islower(grid[i][j]))
        {
            uset.insert(grid[i][j]);
            k--;
            grid[i][j]='.';
        }
        
        int ans=INT_MAX;
        visited[i][j]=true;
        
        if(i>0 && !visited[i-1][j])
        {
            int up=shortestPathUtil(grid,i-1,j,k);
            if(up<INT_MAX)
            {
                up++;
            }
            ans=min(ans,up);
        }
        
        if(i<m-1 && !visited[i+1][j])
        {
            int down=shortestPathUtil(grid,i+1,j,k);
            if(down<INT_MAX)
            {
                down++;
            }
            ans=min(ans,down);
        }
        
        if(j>0 && !visited[i][j-1])
        {
            int left=shortestPathUtil(grid,i,j-1,k);
            if(left<INT_MAX)
            {
                left++;
            }
            ans=min(ans,left);
        }
        
        if(j<n-1 && !visited[i][j+1])
        {
            int right=shortestPathUtil(grid,i,j+1,k);
            if(right<INT_MAX)
            {
                right++;
            }
            ans=min(ans,right);
        }
        
        visited[i][j]=false;
        
        return ans;
    }
public:
    int shortestPathAllKeys(vector<string>& grid) 
    {
//         int k=0;
//         int a;
//         int b;
        
//         m=grid.size();
//         n=grid[0].size();
        
//         for(int i=0; i<grid.size(); i++)
//         {
//             for(int j=0; j<grid[i].size(); j++)
//             {
//                 if(grid[i][j]=='@')
//                 {
//                     a=i;
//                     b=j;
//                     continue;
//                 }
                
//                 if(islower(grid[i][j]))
//                 {
//                     k++;
//                 }
//             }
//         }
        
//         // cout<<a<<" "<<b<<endl;
//         // cout<<k<<endl;
        
//         visited.assign(m,vector<bool>(n,false));
        
//         int ans=shortestPathUtil(grid,a,b,k);
        
//         return ans<INT_MAX?ans:-1;
        int m=grid.size(), n=m?grid[0].size():0;
    if(!m || !n) return 0;
    int path=0, K=0;
    vector<int> dirs={0,-1,0,1,0};
    vector<vector<vector<bool>>> visited(m,vector<vector<bool>>(n,vector<bool>(64,0))); //at most 6 keys, using bitmap 111111
    queue<pair<int,int>> q; //<postion, hold keys mapping>
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='@'){
                q.push({i*n+j,0});
                visited[i][j][0]=1;                    
            }
            if(grid[i][j]>='A' && grid[i][j]<='F') K++; //total alpha number
        }
    }
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int a=q.front().first/n, b=q.front().first%n;
            int carry=q.front().second;
            q.pop();        
            if(carry==((1<<K)-1)) return path; //if all keys hold, just return 
            for(int j=0;j<4;j++){
                int x=a+dirs[j], y=b+dirs[j+1], k=carry;
                if(x<0 || x>=m || y<0 || y>=n || grid[x][y]=='#') continue;
                if(grid[x][y]>='a' && grid[x][y]<='f'){
                    k=carry|(1<<(grid[x][y]-'a')); //update hold keys
                }
                else if(grid[x][y]>='A' && grid[x][y]<='F'){
                    if(!(carry & (1<<(grid[x][y]-'A')))) continue;
                }
                if(!visited[x][y][k]){
                    visited[x][y][k]=1;
                    q.push({x*n+y,k});
               }                
            }
        }
        path++;
    }
    return -1;
    }
};