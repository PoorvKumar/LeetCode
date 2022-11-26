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
        ListNode* p=head;
        ListNode* q=p;
        
        int n=0;
        while(p!=NULL)
        {
            p=p->next;
            n++;
        }
        
        p=head;
        
        //k-1 times to reach kth node from start
        //n-k from start and n-k-(k-1)==n-2k+1 times from current node for kth node from back
        
        int x=k;
        x--;
        
        while(x--)
        {
            p=p->next;
        }
        
        q=head;
        x=n-k;
        
        while(x--)
        {
            q=q->next;
        }
        
        x=q->val;
        q->val=p->val;
        p->val=x;
        
        return head;
    }
};