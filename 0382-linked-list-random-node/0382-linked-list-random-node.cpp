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
    unordered_map<int,int> umap;
    int n;
public:
    Solution(ListNode* head) 
    {
        srand(time(0)); //intialise seed when object of type class Solution declared/created
        
        ListNode* p=head;
        int count=0;
        
        while(p!=NULL)
        {
            umap[count]=p->val;
            count++;
            p=p->next;
        }
        
        n=count;
        
        // for(auto x:umap)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
    }
    
    int getRandom()
    {
        int i=rand()%n;
        // cout<<i<<endl;
        return umap[i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */