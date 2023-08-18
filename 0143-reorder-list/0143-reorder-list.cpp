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
    void reorderList(ListNode* head) 
    {
        ListNode* p=new ListNode(0);
        
        ListNode* h=head;
        
//         ListNode* slow=h;
//         ListNode* fast=h;
        
//         while(fast->next!=NULL && fast!=NULL)
//         {
//             slow=slow->next;
//             fast=fast->next->next;
//         }
        
        int n=0;
        while(h!=NULL)
        {
            n++;
            h=h->next;
        }
        
        h=head;
        ListNode* q=p;
        q->next=h;
        
        int k=n/2+n%2;
        while(k--)
        {
            q=q->next;
            h=h->next;
        }
        
        q->next=NULL;
        p=p->next;
        
        stack<ListNode*> stk;
        if(n%2!=0)
        {
            stk.push(NULL);
        }
        
        while(h!=NULL)
        {
            ListNode* temp=h->next;
            h->next=NULL;
            
            stk.push(h);
            h=temp;
        }
        
        ListNode* dummy=new ListNode(0);
        dummy->next=p;
        
        while(p!=NULL)
        {
            ListNode* temp=p->next;
            p->next=stk.top();
            stk.pop();
            
            p=p->next;
            if(p!=NULL)
            {
                p->next=temp;
                p=p->next;
            }
        }
        
        head=dummy->next;
        return ;
    }
};