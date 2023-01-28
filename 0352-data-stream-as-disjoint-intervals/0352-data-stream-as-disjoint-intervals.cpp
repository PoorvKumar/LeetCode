class SummaryRanges 
{
private:
    // vector<int> vec;
    set<int> st;
    vector<vector<int>> intervals;
public:
    SummaryRanges() 
    {
        // vec.clear();
        st.clear();
    }
    
    void addNum(int value) 
    {
        st.insert(value);
        // if(st.size()==1)
        // {
        //     intervals.push_back({value,value});
        //     return ;
        // }
        intervals.clear();
        
        vector<int> vec(st.begin(),st.end());
        
        int i=0;
        int start=vec[0];
        int end;
        while(i<vec.size())
        {
            start=vec[i];
            end=vec[i];
            while(i<vec.size()-1 && vec[i]==vec[i+1]-1)
            {
                i++;
            }
            end=vec[i];
            intervals.push_back({start,end});
            i++;
        }
    }
    
    vector<vector<int>> getIntervals() 
    {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */