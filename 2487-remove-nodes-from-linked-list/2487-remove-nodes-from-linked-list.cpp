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
    ListNode* removeNodes(ListNode* head) 
    {
        deque<int> dq; //monotonic decreasing doubly-ended queue
        
        ListNode* p=head;
        
        while(p!=NULL)
        {
            if(dq.empty())
            {
                dq.push_back(p->val);
                p=p->next;
                continue;
            }
            
            while(!dq.empty() && dq.back()<p->val)
            {
                dq.pop_back();
            }
            
            dq.push_back(p->val);
            p=p->next;
        }
        
        ListNode* ans=new ListNode();
        p=ans;
        
        while(!dq.empty())
        {
            p->next=new ListNode(dq.front());
            dq.pop_front();
            p=p->next;
        }
        
        return ans->next;
    }
};