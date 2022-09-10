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
    void insert(ListNode* l,int x)
    {
        ListNode* p=l;
        
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=new ListNode;
        p->next->val=x;
        p->next->next=NULL;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* p=new ListNode;
        
        int c=0;
        
        while(l1!=NULL && l2!=NULL)
        {
            insert(p,(l1->val+l2->val+c)%10);
            c=(l1->val+l2->val+c)/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            insert(p,(l1->val+c)%10);
            c=(l1->val+c)/10;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            insert(p,(l2->val+c)%10);
            c=(l2->val+c)/10;
            l2=l2->next;
        }
        
        if(c!=0)
        {
            insert(p,c);
        }
        
        p=p->next;
        
        return p;
    }
};