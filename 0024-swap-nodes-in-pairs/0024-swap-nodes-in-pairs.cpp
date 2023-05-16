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
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* dummy=new ListNode();
        dummy->next=head;
        
        ListNode* prev=dummy;
        ListNode* p=head;
        ListNode* q=p->next;
        
        while(p!=NULL && p->next!=NULL)
        {
            p->next=q->next;
            q->next=p;
            prev->next=q;
            
            prev=p;
            if(p!=NULL && p->next!=NULL)
            {
                p=p->next;
                q=p->next;
            }
        }
        
        return dummy->next;
    }
};