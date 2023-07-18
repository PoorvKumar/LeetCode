class LRUCache 
{
private:
    int capacity;
    unordered_map<int,int> umap;
    list<int> recentlyUsed;
    unordered_map<int,list<int>::iterator> position;
public:
    LRUCache(int capacity) 
    {
        this->capacity=capacity;
    }
    
    int get(int key) 
    {
        if(!umap.count(key))
        {
            return -1;
        }
        
        recentlyUsed.erase(position[key]);
        recentlyUsed.push_front(key);
        
        position[key]=recentlyUsed.begin();
        
        return umap[key];
    }
    
    void put(int key, int value) 
    {
        if(umap.count(key)) //update
        {
            recentlyUsed.erase(position[key]);
            recentlyUsed.push_front(key);
            
            position[key]=recentlyUsed.begin();
            
            umap[key]=value;
            return ;
        }
        
        if(umap.size()<capacity)
        {
            recentlyUsed.push_front(key);
            position[key]=recentlyUsed.begin();
            
            umap[key]=value;
            return ;
        }
        
        int p=recentlyUsed.back();
        recentlyUsed.pop_back();
        
        position.erase(p);
        umap.erase(p);
        
        recentlyUsed.push_front(key);
        position[key]=recentlyUsed.begin();
        
        umap[key]=value;
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */