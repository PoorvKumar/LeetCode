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
    ListNode* insertHead(ListNode* head,int val)
    {
        ListNode* p;
        p=new ListNode();
        p->val=val;
        p->next=head;
        head=p;
        
        return head;
    }
    
    int countRemaining(ListNode* head)
    {
        int sum=0;
        while(head!=NULL)
        {
            sum++;
            head=head->next;
        }
        
        return sum;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* p;
        p=new ListNode();
        p->next=NULL;
        
        int n=countRemaining(head);
        
        ListNode* q;
        
        while(head!=NULL && n>=k)
        {
            q=p;
            ListNode* tmp=NULL;
            int x=k;
            
            while(x--)
            {
                if(head!=NULL)
                {
                    tmp=insertHead(tmp,head->val);
                    head=head->next;
                    n--;
                }
            }
            
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=tmp;
        }
        
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=head;
        
        p=p->next;
        
        return p;
    }
};