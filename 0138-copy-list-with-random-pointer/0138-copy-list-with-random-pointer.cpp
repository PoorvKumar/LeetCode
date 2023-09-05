/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution 
{
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*,Node*> umap;
        
        Node* copyList=new Node(0);
        Node* q=copyList;
        
        Node* p=head;
        while(p!=NULL)
        {
            Node* newNode=new Node(p->val);
            q->next=newNode;
            q=q->next;
            
            umap[p]=newNode;
            p=p->next;
        }
        
        p=head;
        q=copyList->next;
        
        while(p!=NULL)
        {
            q->random=umap[p->random];
            
            q=q->next;
            p=p->next;
        }
        
        return copyList->next; 
        //TC: O(2*n)
        //SC: O(n)+O(n)
    }
};