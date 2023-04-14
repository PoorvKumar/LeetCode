class Solution 
{
private:
    int n;
    vector<vector<int>> marked;
    // vector<vector<int>> queens;
    
    vector<vector<string>> res;
    
    bool nQueensUtil(vector<string>& vec,int index)
    {
        if(index==n-1) //base case
        {
            for(int i=0; i<n; i++)
            {
                if(marked[index][i]==0)
                {
                    string str="";
                    for(int j=0; j<n; j++)
                    {
                        str=str+(j!=i?'.':'Q');
                    }
                    vec.push_back(str);
                    res.push_back(vec);
                    
                    vec.pop_back();
                    
                    return true;
                }
            }
            
            return false;
        }
        
        for(int i=0; i<n; i++)
        {
            if(marked[index][i]==0)
            {
                mark(index,i); //mark queen
                string str="";
                for(int j=0; j<n; j++)
                {
                    str=str+(j!=i?'.':'Q');
                }
                vec.push_back(str);
                
                nQueensUtil(vec,index+1);
                
                vec.pop_back();
                unmark(index,i);
            }
        }
        
        return false;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        this->n=n;
        marked.assign(n,vector<int>(n,0));
        // queens.assign(n,vector<int>(2,-1));
        
        vector<string> vec;
        nQueensUtil(vec,0);
        
        return res;
    }
    
private:
    void mark(int i,int j)
    {
        for(int k=0; k<n; k++)
        {
            marked[i][k]++;
        }
        
        marked[i][j]=10000;
        
        
        int p=i+1;
        int q=j-1;
        int s=j+1;
        
        while(p<n)
        {
            marked[p][j]++;
            if(q>=0)
            {
                marked[p][q--]++;
            }
            if(s<n)
            {
                marked[p][s++]++;
            }
            p++;
        }
        
        return ;
    }
    
    void unmark(int i,int j)
    {
        for(int k=0; k<n; k++)
        {
            marked[i][k]--;
        }
        
        marked[i][j]=0;
        
        
        int p=i+1;
        int q=j-1;
        int s=j+1;
        
        while(p<n)
        {
            marked[p][j]--;
            if(q>=0)
            {
                marked[p][q--]--;
            }
            if(s<n)
            {
                marked[p][s++]--;
            }
            p++;
        }
        
        return ;
    }
};