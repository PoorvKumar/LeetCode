/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            if(head!=NULL)
            {
                return new TreeNode(head->val);
            }
            
            return NULL;
        }
        
        TreeNode* root=new TreeNode();
        
        ListNode* p=new ListNode();
        p->next=head;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            p=p->next;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        root->val=slow->val;
        
        root->right=sortedListToBST(slow->next); //RST
        p->next=NULL;
        root->left=sortedListToBST(head); //LST
        
        return root;
    }
};