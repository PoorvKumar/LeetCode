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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p=list1;
        a--;
        
        while(a--)
        {
            p=p->next;
        }
        
        ListNode* q=list1;
        
        while(b--)
        {
            q=q->next;
        }
        
        p->next=list2;
        
        while(p->next!=NULL)
        {
            p=p->next;
        }
        
        p->next=q->next;
        
        return list1;
    }
};