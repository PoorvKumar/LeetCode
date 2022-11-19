class LRUCache 
{
private:
    unordered_map<int ,pair<int,int>> lru;
    set<pair<int,int>> ageBit;
    int capacity;
    int age=0;
    
public:
    LRUCache(int capacity) 
    {
        this->capacity=capacity;
        age=0;
    }
    
    int get(int key) 
    {
        int x=-1;
        if(!lru.count(key))
        {
            return -1;
        }
        int agebit=lru[key].first;
        x=lru[key].second;
        lru[key].first=++age;
        
        ageBit.erase(ageBit.find({agebit,key}));
        ageBit.insert(pair<int,int>(age,key));
        
        return x;
    }
    
    void put(int key, int value) 
    {
        if(lru.count(key))
        {
            int x=lru[key].first;
            lru[key].first=++age;
            lru[key].second=value;
            
            ageBit.erase(ageBit.find({x,key}));
            ageBit.insert({age,key});
            return;
        }
        
        if(lru.size()==capacity)
        {
            int xkey=(*ageBit.begin()).second;
            ageBit.erase(ageBit.begin());
            lru.erase(xkey);
            
            lru[key].first=++age;
            lru[key].second=value;
            ageBit.insert({age,key});
            return;
        }
        
        lru[key].first=++age;
        lru[key].second=value;
        ageBit.insert({age,key});
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */