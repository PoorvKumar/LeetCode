/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
private:
    unordered_map<string,int> umap;
    vector<TreeNode*> vec;
    
    string postOrderTraversal(TreeNode* root)
    {
        if(root!=NULL)
        {
            string l=postOrderTraversal(root->left);
            string r=postOrderTraversal(root->right);
            string R=to_string(root->val);
            
            // string str=l+R+r;
            string str=l+','+r+','+R; //important to signify the traversal as to_string() string 12 2 and 1 22 cannot be differentiated
            if(umap[str]==1)
            {
                vec.push_back(root);
            }
            
            umap[str]++;
            return str;
        }
        return "#"; //instead of empty string else might give error
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        postOrderTraversal(root); //using inOrderTraversal() gives error when inorder traversal for different subtrees same
        
        return vec;
    }
};