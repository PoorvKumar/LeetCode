//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
private:
    int m;
    int n;
    vector<vector<bool>> visited;

    bool isWordExistUtil(vector<vector<char>>& board,string& word,int i,int j,int index)
    {
        if(index==word.size()-1)
        {
            return board[i][j]==word[index];
        }
        
        if(board[i][j]!=word[index])
        {
            return false;
        }
        
        visited[i][j]=true;
        
        bool ans=false;
        
        //up
        if(i>0 && !visited[i-1][j])
        {
            ans=isWordExistUtil(board,word,i-1,j,index+1);
            if(ans)
            {
                return true;
            }
        }
        
        //down
        if(i<m-1 && !visited[i+1][j])
        {
            ans=isWordExistUtil(board,word,i+1,j,index+1);
            if(ans)
            {
                return true;
            }
        }
        
        //left
        if(j>0 && !visited[i][j-1])
        {
            ans=isWordExistUtil(board,word,i,j-1,index+1);
            if(ans)
            {
                return true;
            }
        }
        
        //right
        if(j<n-1 && !visited[i][j+1])
        {
            ans=isWordExistUtil(board,word,i,j+1,index+1);
            if(ans)
            {
                return true;
            }
        }
        
        visited[i][j]=false;
        
        return false;
    }
public:
    bool isWordExist(vector<vector<char>>& board, string& word) 
    {
        m=board.size();
        n=board[0].size();
        
        visited.assign(m,vector<bool>(n,false));
        
        vector<pair<int,int>> vec;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]==word[0])
                {
                    vec.push_back({i,j});
                }
            }
        }
        
        bool ans=false;
        
        for(auto x:vec)
        {
            ans=isWordExistUtil(board,word,x.first,x.second,0);
            if(ans)
            {
                return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends