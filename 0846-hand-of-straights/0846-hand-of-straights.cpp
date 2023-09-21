class Solution 
{
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        if(hand.size()%groupSize!=0)
        {
            return false;
        }
        
        int n=hand.size()/groupSize;
        
        vector<vector<int>> vec(n,vector<int>());
        
        sort(hand.begin(),end(hand));
        
        // cout<<n<<endl;
        
        for(auto x:hand)
        {
            bool flag=false;
            for(int i=0; i<n; i++)
            {
                if(vec[i].size()<groupSize && (vec[i].empty() || vec[i].back()+1==x))
                {
                    vec[i].push_back(x);
                    flag=true;
                    break;
                }
            }
            
            if(!flag)
            {
                return false;
            }
        }
        
        return true;
    }
};