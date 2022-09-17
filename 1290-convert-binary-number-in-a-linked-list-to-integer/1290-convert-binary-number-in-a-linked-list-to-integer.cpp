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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* head1;
        head1=NULL;
        
        while(head!=NULL)
        {
            ListNode* tmp;
            tmp=new ListNode(head->val);
            tmp->next=head1;
            head1=tmp;
            head=head->next;
        }
        
        return head1;
    }
    
    int getDecimalValue(ListNode* head) 
    {
        ListNode* p;
        p=reverseList(head);
        
        int sum=0;
        int i=0;
        
        while(p!=NULL)
        {
            if(p->val==1)
            {
                sum=sum+pow(2,i);
            }
            i++;
            p=p->next;
        }
        
        return sum;
    }
};