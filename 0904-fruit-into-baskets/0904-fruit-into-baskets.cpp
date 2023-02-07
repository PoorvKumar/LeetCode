class Solution 
{
public:
    int totalFruit(vector<int>& fruits) 
    {
        int maxim=0;
        
        vector<pair<int,int>> vec;
        int a;
        int b;
        
        for(int i=0; i<fruits.size(); i++)
        {
            int x=fruits[i];
            int j=i+1;
            while(j<fruits.size() && fruits[j]==x)
            {
                j++;
            }
            vec.push_back({x,j-i});
            i=j-1;
        }
        
        // for(auto x:vec)
        // {
        //     cout<<"{"<<x.first<<"->"<<x.second<<"}"<<" ";
        // }
        // cout<<endl;
        
        if(vec.size()==1)
        {
            return vec[0].second;
        }
        
        for(int i=1; i<vec.size(); i++)
        {
            a=vec[i-1].first;
            b=vec[i].first;
            int sum=vec[i-1].second+vec[i].second;
            int j=i+1;
            while(j<vec.size() && (vec[j].first==a || vec[j].first==b))
            {
                sum=sum+vec[j].second;
                j++;
            }
            
            maxim=max(maxim,sum);
            i=j-1;
        }
        
        return maxim;
    }
};