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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
    {
        unordered_map<ListNode*,int> umap;
        
        ListNode* p=headA;
        int i=0;
        while(p!=NULL)
        {
            umap[p]=i++;
            p=p->next;
        }
        
        ListNode* q=headB;
        int index=-1;
        while(q!=NULL)
        {
            if(umap.count(q))
            {
                index=umap[q];
                break;
            }
            q=q->next;
        }
        
        if(index==-1)
        {
            return NULL;
        }
        
        p=headA;
        while(index--)
        {
            p=p->next;
        }
        
        return p;
    }
};