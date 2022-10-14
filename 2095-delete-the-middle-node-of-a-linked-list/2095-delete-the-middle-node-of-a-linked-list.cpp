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
    ListNode* deleteMiddle(ListNode* head)
    {
        int n=0;
        
        ListNode* p;
        p=head;
        
        while(p!=NULL)
        {
            p=p->next;
            n++;
        }
        
        n=(n!=1)?n/2:0;
        
        if(n==0)
        {
            return NULL;
        }
        
        p=head;
        ListNode* q=p;
        
        while(n--)
        {
            q=p;
            p=p->next;
        }
        
        q->next=p->next;
        delete p;
        
        return head;
    }
};