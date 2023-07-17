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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> stk1;
        stack<int> stk2;
        
        ListNode* p=l1;
        
        while(p!=NULL)
        {
            stk1.push(p->val);
            p=p->next;
        }
        
        p=l2;
        
        while(p!=NULL)
        {
            stk2.push(p->val);
            p=p->next;
        }
        
        int s=0;
        int c=0;
        
        ListNode* l=NULL;
        
        while(!stk1.empty() && !stk2.empty())
        {
            int a=stk1.top();
            stk1.pop();
            
            int b=stk2.top();
            stk2.pop();
            
            s=(a+b+c)%10;
            c=(a+b+c)/10;
            
            ListNode* node=new ListNode(s);
            node->next=l;
            
            l=node;
        }
        
        if(!stk1.empty() || !stk2.empty())
        {
            while(!stk1.empty())
            {
                int a=stk1.top();
                stk1.pop();
                
                s=(a+c)%10;
                c=(a+c)/10;
                
                ListNode* q=new ListNode(s);
                q->next=l;
                l=q;
            }
            
            while(!stk2.empty())
            {
                int b=stk2.top();
                stk2.pop();
                
                s=(b+c)%10;
                c=(b+c)/10;
                
                ListNode* q=new ListNode(s);
                q->next=l;
                l=q;
            }
        }
        
        if(c!=0)
        {
            ListNode* q=new ListNode(c);
            q->next=l;
            l=q;
        }
        
        return l; 
        //TC: O(max(m,n))
        //SC: O(m+n)
    }
};