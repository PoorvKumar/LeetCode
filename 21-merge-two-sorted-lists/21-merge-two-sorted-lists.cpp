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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* list=new ListNode();
        ListNode* p;
        p=list;
        
        while(list1 && list2)
        {
            if(list1->val<list2->val)
            {
                p->next=new ListNode;
                p=p->next;
                p->val=list1->val;
                p->next=NULL;
                list1=list1->next;
            }
            else
            {
                p->next=new ListNode;
                p=p->next;
                p->val=list2->val;
                p->next=NULL;
                list2=list2->next;
            }
        }
        
        while(list1)
        {
            p->next=new ListNode;
            p=p->next;
            p->val=list1->val;
            p->next=NULL;
            list1=list1->next;
        }
        
        while(list2)
        {
            p->next=new ListNode;
            p=p->next;
            p->val=list2->val;
            p->next=NULL;
            list2=list2->next;
        }
        
        list=list->next;
        
        return list;
    }
};