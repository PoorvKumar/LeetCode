/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution 
{
private:
    unordered_map<int,Node*> umap;
public:
    Node* cloneGraph(Node* node) 
    {
        if(node==NULL)
        {
            return NULL;
        }
        
        if(umap.count(node->val))
        {
            return umap[node->val];
        }
        
        Node* newNode=new Node(node->val);
        vector<Node*> vec(node->neighbors.size());
        
        umap[node->val]=newNode;
        int n=node->neighbors.size();
        
        for(int i=0; i<n; i++)
        {
            vec[i]=cloneGraph(node->neighbors[i]);
        }
        
        newNode->neighbors=vec;
        return newNode;
    }
};