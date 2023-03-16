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
        stack<int> stk; //monotonic decreasing stack
        
        ListNode* p=head;
        
        while(p!=NULL)
        {
            if(stk.empty())
            {
                stk.push(p->val);
                p=p->next;
                continue;
            }
            
            while(!stk.empty() && stk.top()<p->val)
            {
                // cout<<stk.top()<<" "<<p->val<<endl;
                stk.pop();
            }
            
            stk.push(p->val);
            p=p->next;
        }
        
        // cout<<stk.size()<<endl;
        
        vector<int> vec;
        while(!stk.empty())
        {
            vec.push_back(stk.top());
            stk.pop();
        }
        
        reverse(vec.begin(),vec.end());
        
        // for(auto x:vec)
        // {
        //     cout<<x<<" ";
        // }
        
        ListNode* ans=new ListNode();
        // ListNode* p=ans;
        p=ans;
        
        for(auto x:vec)
        {
            p->next=new ListNode(x);
            p=p->next;
        }
        
        return ans->next;
    }
};