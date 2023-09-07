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
private:
    ListNode* reverseList(ListNode* head)
    {
        stack<ListNode*> stk;
        
        ListNode* p=head;
        while(p!=NULL)
        {
            ListNode* tmp=p->next;
            p->next=NULL;
            stk.push(p);
            p=tmp;
        }
        
        ListNode* q=new ListNode(0);
        ListNode* r=q;
        
        while(!stk.empty())
        {
            r->next=stk.top();
            r=r->next;
            stk.pop();
        }
        
        return q->next;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode* p=head;
        int l=left;
        
        l--;
        
        ListNode* q=new ListNode(0);
        ListNode* s=q;
        q->next=head;
        
        while(l--)
        {
            q=q->next;
            p=p->next;
        }
        
        int k=right-left;
        ListNode* r=p;
        
        while(k--)
        {
            r=r->next;
        }
        
        ListNode* tmp=r->next;
        r->next=NULL;
        
        p=reverseList(p);
        
        q->next=p;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        
        p->next=tmp;
        
        return s->next; 
        //TC: O(n)
        //SC: O(1)
    }
};