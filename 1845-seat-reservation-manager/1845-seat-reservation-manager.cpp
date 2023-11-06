class SeatManager 
{
private:
    vector<bool> available;
    set<int> st;
public:
    SeatManager(int n) 
    {
        available.assign(n,false);
        for(int i=1; i<=n; i++)
        {
            st.insert(i);
        }
    }
    
    int reserve() 
    {
        int seat=*st.begin();
        
        st.erase(seat);
        available[seat-1]=false;
        
        return seat;
    }
    
    void unreserve(int seatNumber) 
    {
        available[seatNumber-1]=true;
        st.insert(seatNumber);
        
        return ;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */