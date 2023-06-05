class Solution 
{
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        if(coordinates.size()==2)
        {
            return true;
        }
        
        unordered_set<double> uset;
        
        for(int i=0; i<coordinates.size(); i++)
        {
            int x1=coordinates[i][0];
            int y1=coordinates[i][1];
            
            for(int j=i+1; j<coordinates.size(); j++)
            {
                if(uset.size()>1)
                {
                    return false;
                }
                
                int x2=coordinates[j][0];
                int y2=coordinates[j][1];
                
                double m=(double)(y2-y1)/((x2-x1)*1.0);
                if(isinf(m))
                {
                    m=INT_MAX;
                }
                
                uset.insert(m);
            }
        }
        
        // for(auto x:uset)
        // {
        //     cout<<x<<" ";
        // }
        
        return uset.size()==1;
    }
};