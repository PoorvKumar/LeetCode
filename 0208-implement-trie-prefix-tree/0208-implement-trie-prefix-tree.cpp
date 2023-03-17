class Trie 
{
private:
    class TrieNode
    {
    public:
        vector<TrieNode*> children;
        bool isEnd=false; //in-class initializer
        
        // TrieNode() //non-parameterised constructor
        // {
        //     children.assign(26,NULL);
        //     isEnd=false;
        // }
        
        TrieNode(): children(vector<TrieNode*>(26,NULL)), isEnd(false) {}; //delegation of constructor
    };
    
    TrieNode* root;
public:
    Trie() 
    {
        root=new TrieNode();
    }
    
    void insert(string word) 
    {
        TrieNode* p=root;
        for(auto x:word)
        {
            int index=x-'a';
            if(p->children[index]==NULL)
            {
                p->children[index]=new TrieNode();
            }
            p=p->children[index];
        }
        p->isEnd=true;
        return ;
    }
    
    bool search(string word)
    {
        TrieNode* p=root;
        
        for(auto x:word)
        {
            if(p==NULL)
            {
                return false;
            }
            
            int index=x-'a';
            p=p->children[index];
        }
        
        return p!=NULL && p->isEnd;
    }
    
    bool startsWith(string prefix)
    {
        TrieNode* p=root;
        for(auto x:prefix)
        {
            if(p==NULL)
            {
                return false;
            }
            
            int index=x-'a';
            p=p->children[index];
        }
        
        return p!=NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */