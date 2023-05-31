class UndergroundSystem 
{
private:
    unordered_map<int,pair<string,int>> umapS;
    unordered_map<int,pair<string,int>> umapE;
    
    unordered_map<string,unordered_map<string,vector<int>>> umap;
public:
    UndergroundSystem() 
    {
        umapS.clear();
        umapE.clear();
        
        umap.clear();
    }
    
    void checkIn(int id, string start, int t) 
    {
        umapS[id]={start,t};
        return ;
    }
    
    void checkOut(int id, string end, int t) 
    {
        // umapE[id][end]=t;
        string start=umapS[id].first;
        umap[start][end].push_back(t-umapS[id].second);
        
        umapS.erase(id);
        
        return ;
    }
    
    double getAverageTime(string start, string end) 
    {
        vector<int> vec=umap[start][end];
        int val=accumulate(vec.begin(),vec.end(),0);
        int n=vec.size();
        
        return (double)(val/(n*1.0));
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */