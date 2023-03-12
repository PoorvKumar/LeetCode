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
    ListNode* merge(ListNode* p1,ListNode* p2)
    {        
        ListNode* head=new ListNode();
        ListNode* p=head;
        
        while(p1!=NULL && p2!=NULL) //TC: O(n+m)
        {
            if(p1->val<=p2->val)
            {
                p->next=new ListNode(p1->val);
                p1=p1->next;
            }
            else
            {
                p->next=new ListNode(p2->val);
                p2=p2->next;
            }
            p=p->next;
        }
        
        if(p1!=NULL)
        {
            p->next=p1;
        }
        else
        {
            p->next=p2;
        }
        
        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
        {
            return NULL;
        }
        
        if(lists.size()==1)
        {
            return lists[0];
        }
        
//         ListNode* p1=lists[lists.size()-1];
//         lists.pop_back();
        
//         ListNode* p2=lists[lists.size()-1];
//         lists.pop_back();
        
//         p1=merge(p1,p2); //TC: O(n+m)
        
//         if(!lists.empty())
//         {
//             p2=lists[lists.size()-1];
//             lists.pop_back();
            
//             p1=merge(p1,p2);
//         }
        
//         lists.push_back(p1);
        
//         return mergeKLists(lists); // 132 / 133 testcases passed giving TLE at last testcase
//         //TC: O(k) + O(n+m) 
//         //SC: O(n+m)
        
        priority_queue<int,vector<int>,greater<int>> pq; //min heap
        
        for(auto head:lists)
        {
            while(head!=NULL)
            {
                pq.push(head->val);
                head=head->next;
            }
        }
        
        ListNode* head=new ListNode();
        ListNode* p=head;
        
        while(!pq.empty())
        {
            p->next=new ListNode(pq.top());
            pq.pop();
            p=p->next;
        }
        
        return head->next;
    }
};