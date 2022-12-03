class Solution 
{
private:
    static bool sortBySecDesc(pair<char,int> &a, pair<char,int> &b)
    {
        return a.second>b.second;
    }
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> umap;
        // vector<int> countFreq(123); //A-Z->[65,90] a-z->[97,122]
        
        for(int i=0; i<s.length(); i++)
        {
            umap[s[i]]++;
            // countFreq[s[i]]++;
        }
        
        vector<pair<int,char>> vec;
        for(auto x:umap)
        {
            vec.push_back({x.second,x.first});
            // vec.push_back(make_pair(x.second,x.first));
        }
        
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        
        int j=0;
        
        for(int i=0; i<vec.size(); i++)
        {
            while(vec[i].first--)
            {
                s[j++]=vec[i].second;
            }
        }
        
        return s;
    }
};