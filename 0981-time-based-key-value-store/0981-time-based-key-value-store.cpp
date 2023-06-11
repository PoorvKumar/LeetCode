class TimeMap 
{
private:
    unordered_map<string,map<int,string>> umap;
public:
    TimeMap() 
    {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        umap[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) 
    {
        auto it=umap[key].upper_bound(timestamp);
        // return it==umap[key].begin()?"":prev(it)->second;
        return it==begin(umap[key])?"":prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */