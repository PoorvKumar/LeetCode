/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* detectCycle(ListNode* head) 
    {
        ListNode* p=head;
        
        unordered_set<ListNode*> uset;
        
        while(p!=NULL)
        {
            if(uset.count(p))
            {
                return p;
            }
            
            uset.insert(p);
            p=p->next;
        }
        
        return p;
    }
};