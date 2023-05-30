class MyHashSet 
{
private:
    vector<bool> hash;
public:
    MyHashSet() 
    {
        hash.assign(1e6+1,false);
    }
    
    void add(int key)
    {
        hash[key]=true;
        return ;
    }
    
    void remove(int key) 
    {
        hash[key]=false;
        return ;
    }
    
    bool contains(int key) 
    {
        return hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */