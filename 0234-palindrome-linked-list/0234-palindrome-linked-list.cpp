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
    bool isPalindrome(ListNode* head) 
    {
        ListNode* p=head;
        
        int n=0;
        
        while(p)
        {
            p=p->next;
            n++;
        }
        
        p=head;
        
        int x=n/2;
        
        stack<int> s;
        
        for(int i=0; i<x; i++)
        {
            s.push(p->val);
            p=p->next;
        }
        
        if(n%2!=0)
        {
            p=p->next;
        }
        
        for(int i=0; i<x; i++)
        {
            if(s.top()==p->val)
            {
                s.pop();
                p=p->next;
            }
        }
        
        return s.empty();
    }
};