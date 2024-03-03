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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* p=head;
        
        int k=0;
        
        while(p!=NULL)
        {
            k++;
            p=p->next;
        }
        
        if(k==1 && n==1)
        {
            return NULL;
        }
        if(k==n)
        {
            head=head->next;
            return head;
        }
        
        n=k-n;
        
        p=head;
        ListNode* q=p;
        
        while(n>0 && n--)
        {
            q=p;
            p=p->next;
        }
        
        q->next=p->next;
        
        return head;
    }
};