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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* p=new ListNode(0);
        ListNode* q=p;
        
        ListNode* r=new ListNode(0);
        ListNode* s=r;
        
        ListNode* h=head;
        
        while(h!=NULL)
        {
            if(h->val<x)
            {
                q->next=new ListNode(h->val);
                q=q->next;
            }
            else
            {
                s->next=new ListNode(h->val);
                s=s->next;
            }
            h=h->next;
        }
        
        r=r->next;
        q->next=r;
        
        return p->next;
    }
};