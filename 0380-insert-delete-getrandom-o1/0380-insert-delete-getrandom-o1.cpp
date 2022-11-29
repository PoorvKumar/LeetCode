class RandomizedSet 
{
private:
    unordered_set<int> uset;
public:
    RandomizedSet() 
    {
        srand(time(0));
    }
    
    bool insert(int val) 
    {
        if(uset.count(val)==1)
        {
            return false;
        }
        else
        {
            uset.insert(val);
            return true;
        }
    }
    
    bool remove(int val) 
    {
        if(uset.count(val)==1)
        {
            uset.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() 
    {        
        int x=(rand()%uset.size())+0; //(rand()%max)+min //[min,max]
        //rand() in c++ stl in stdlib.h 
        
        // int x=0;
        // if(x==uset.size())
        // {
        //     x--;
        // }
        
        unordered_set<int>::iterator it=uset.begin();
        advance(it,x);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */