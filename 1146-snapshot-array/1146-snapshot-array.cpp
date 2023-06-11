class SnapshotArray 
{
private:
    // vector<int> vec;
    vector<vector<pair<int,int>>> snapArr;
    int snapId=0;
public:
    SnapshotArray(int length) 
    {
        // vec.assign(length,0);
        snapArr.assign(length,vector<pair<int,int>>());
    }
    
    void set(int index, int val) 
    {
        // vec[index]=val;
        if(snapArr[index].empty() || snapArr[index].back().first!=snapId)
        {
            snapArr[index].push_back({snapId,val});
            return;
        }
        snapArr[index].back().second=val;
    }
    
    int snap()
    {
        // int i=0;
        // for(auto x:vec)
        // {
        //     snapArr[i].push_back({snapId,x});
        //     i++;
        // }
        
        // for(int i=0; i<vec.size(); i++)
        // {
        //     snapArr[i].push_back({snapId,vec[i]});
        // }
        
        return snapId++;
    }
    
    int get(int index, int snap_id) 
    {
        auto it=upper_bound(snapArr[index].begin(),snapArr[index].end(),pair<int,int>({snap_id,INT_MAX}));
        return it==begin(snapArr[index])?0:prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */