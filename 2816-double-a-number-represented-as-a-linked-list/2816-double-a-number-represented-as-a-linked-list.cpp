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
    pair<ListNode*,int> doubleItUtil(ListNode* head)
    {
        if(head->next==NULL)
        {
            int val=head->val*2;
            head->val=val%10;
            int carry=val/10;
            
            return {head,carry};
        }
        
        pair<ListNode*,int> p=doubleItUtil(head->next);
        
        int val=head->val*2+p.second;
        head->val=val%10;
        
        head->next=p.first;
        
        int carry=val/10;
        
        return {head,carry};
    }
public:
    ListNode* doubleIt(ListNode* head) 
    {
        pair<ListNode*,int> p=doubleItUtil(head);
        
        if(p.second!=0)
        {
            ListNode* newHead=new ListNode(p.second);
            newHead->next=p.first;
            
            return newHead;
        }
        
        return p.first;
    }
};