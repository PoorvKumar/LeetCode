class Solution 
{
private:
    vector<bool> visited;
    
    bool validateBinaryTreeUtil(vector<int>& leftChild,vector<int>& rightChild,int root)
    {
        visited[root]=true;
        
        if(leftChild[root]!=-1)
        {
            if(!visited[leftChild[root]])
            {
                if(!validateBinaryTreeUtil(leftChild,rightChild,leftChild[root]))
                {
                    return false;
                }
            }
            else
            {
                // cout<<root<<endl;
                return false;
            }
        }
        
        if(rightChild[root]!=-1)
        {
            if(!visited[rightChild[root]])
            {
                if(!validateBinaryTreeUtil(leftChild,rightChild,rightChild[root]))
                {
                    return false;
                }
            }
            else
            {
                // cout<<root<<endl;
                return false;
            }
        }
        
        return true;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        // visited.assign(n,false);
        
        for(int i=0; i<n; i++)
        {
            visited.assign(n,false);
            if(validateBinaryTreeUtil(leftChild,rightChild,i))
            {
                bool flag=true;
                
                for(auto x:visited)
                {
                    if(!x)
                    {
                        // return false;
                        flag=false;
                    }
                }
                
                if(flag)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};