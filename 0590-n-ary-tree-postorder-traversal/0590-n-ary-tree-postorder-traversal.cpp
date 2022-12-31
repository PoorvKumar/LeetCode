/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> postorder(Node* root)
    {
        vector<int> vec;
        
        if(root!=NULL)
        {
            for(int i=0; i<root->children.size(); i++)
            {
                vector<int> ans=postorder(root->children[i]);
                for(auto x:ans)
                {
                    vec.push_back(x);
                }
            }
            
            vec.push_back(root->val);
        }
        
        return vec;
    }
};