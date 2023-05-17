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
    int pairSum(ListNode* head) 
    {
        int n=0;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            n++;
        }
        
        n=n*2;
        // cout<<n<<endl;
        
        ListNode* p=head;
        
        int i=0;
        while(i<n/2)
        {
            p=p->next;
            i++;
        }
        
        vector<int> vec;
        
        while(p!=NULL)
        {
            vec.push_back(p->val);
            p=p->next;
        }
        
        int maxim=0;
        p=head;
        
        for(vector<int>::reverse_iterator rit=vec.rbegin(); rit!=vec.rend(); rit++)
        {
            maxim=max(maxim,p->val+*rit);
            p=p->next;
        }
        
        return maxim;
    }
};