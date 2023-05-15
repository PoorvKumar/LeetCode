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
class Solution 
{
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        int n=0;
        ListNode* dummy=head;
        while(dummy)
        {
            n++;
            dummy=dummy->next;
        }
        
        ListNode* p=head;
        int i=1;
        
        while(i<k && p!=NULL)
        {
            p=p->next;
            i++;
        }
        
        ListNode* q=head;
        i=0;
        while(i<n-k && q!=NULL)
        {
            q=q->next;
            i++;
        }
        
        int temp=p->val;
        p->val=q->val;
        q->val=temp;
        
        return head;
    }
};