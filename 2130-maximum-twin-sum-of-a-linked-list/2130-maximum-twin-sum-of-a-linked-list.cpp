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
    int pairSum(ListNode* head) 
    {
        int n=0;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            n++;
        }
        
        n=n*2;
        // cout<<n<<endl;
        
        ListNode* p=head;
        ListNode* q;
        
        int i=0;
        while(i<n/2)
        {
            p=p->next;
            i++;
        }
        
        q=p;
        
        ListNode* r=new ListNode();
        
        while(p!=NULL)
        {
            r->val=p->val;
            p=p->next;
            
            ListNode* node=new ListNode();
            node->next=r;
            r=node;
        }
        r=r->next;
        
        int maxim=0;
        p=head;
        
        while(r!=NULL)
        {
            // cout<<r->val<<" ";
            maxim=max(maxim,p->val+r->val);
            p=p->next;
            r=r->next;
        }
        
        return maxim;
    }
};