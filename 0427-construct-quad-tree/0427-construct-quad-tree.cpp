/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution 
{
private:
    Node* constructUtil(vector<vector<int>>& grid,int i,int j,int n) //constructUtil(grid,i,j,size)
    {
        Node* root=new Node();
        
        bool one=false;
        bool zero=false;
        
        for(int x=i; x<i+n; x++)
        {
            for(int y=j; y<j+n; y++)
            {
                if(one && zero)
                {
                    break;
                }
                if(grid[x][y]==1)
                {
                    one=true;
                }
                else
                {
                    zero=true;
                }
            }
            if(one && zero)
            {
                break;
            }
        }
        
        if(!one || !zero) //base case
        {
            if(!one)
            {
                root->val=0;
            }
            else
            {
                root->val=1;
            }
            root->isLeaf=true;
            
            return root; 
        }
        
        root->val=1;
        root->isLeaf=false;
        
        Node* topL=constructUtil(grid,i,j,n/2);
        Node* topR=constructUtil(grid,i,j+n/2,n/2);
        Node* bottomL=constructUtil(grid,i+n/2,j,n/2);
        Node* bottomR=constructUtil(grid,i+n/2,j+n/2,n/2);
        
        root->topLeft=topL;
        root->topRight=topR;
        root->bottomLeft=bottomL;
        root->bottomRight=bottomR;
        
        return root;
    }
public:
    Node* construct(vector<vector<int>>& grid)
    {
        return constructUtil(grid,0,0,grid.size());
    }
};