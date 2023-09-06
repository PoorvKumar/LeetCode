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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*> vec;
        
        ListNode* p=head;
        int n=0;
        
        while(p!=NULL)
        {
            n++;
            p=p->next; 
        }
        
        p=head;
        
        while(p!=NULL)
        {
            int N=n/k+(n%k!=0);
            
            // cout<<n<<" "<<N<<" "<<p->val<<endl;
            if(n%k!=0)
            {
                n--;
            }
            
            if(N>0)
            {
                N--;
            }
            
            ListNode* q=p;
            
            while(N--)
            {
                q=q->next;
            }
            
            ListNode* tmp=q->next;
            q->next=NULL;
            
            vec.push_back(p);
            p=tmp;
        }
        
        int N=k-vec.size();
        while(N--)
        {
            vec.push_back(NULL);
        }
        
        return vec;
    }
};