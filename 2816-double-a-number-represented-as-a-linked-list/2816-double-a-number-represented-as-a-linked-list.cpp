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
    int doubleItUtil(ListNode* head)
    {
        if(head->next==NULL)
        {
            int val=head->val*2;
            head->val=val%10;
            int carry=val/10;
            
            // return {head,carry};
            return carry;
        }
        
        // pair<ListNode*,int> p=doubleItUtil(head->next);
        int c=doubleItUtil(head->next);
        
        int val=head->val*2+c;
        head->val=val%10;
        
        int carry=val/10;
        return carry;
    }
public:
    ListNode* doubleIt(ListNode* head) 
    {
        // pair<ListNode*,int> p=doubleItUtil(head);
        int carry=doubleItUtil(head);
        
        if(carry!=0)
        {
            ListNode* newHead=new ListNode(carry);
            newHead->next=head;
            
            return newHead;
        }
        
        return head;
    }
};