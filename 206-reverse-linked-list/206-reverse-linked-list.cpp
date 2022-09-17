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
    void insert(ListNode* ptr,int x)
    {
        ListNode* p=new ListNode;
        
        p->val=x;
        p->next=ptr->next;
        ptr->next=p;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* p;
        p=NULL;
        
        while(head)
        {
            // insert(p,head->val);
            // head=head->next;
            ListNode* tmp=new ListNode(head->val);
            tmp->next=p;
            p=tmp;           
            head=head->next;
        }
        
        return p;
    }
};