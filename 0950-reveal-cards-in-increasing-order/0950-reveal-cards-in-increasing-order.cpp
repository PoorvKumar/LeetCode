class Solution 
{
private:
    vector<int> getRevealingOrder(int n)
    {
        vector<int> vec;
        queue<int> q;
        
        for(int i=0; i<n; i++)
        {
            q.push(i);
        }
        
        while(!q.empty())
        {
            vec.push_back(q.front());
            q.pop();
            
            q.push(q.front());
            q.pop();
        }
        
        return vec;
    }
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        vector<int> vec=getRevealingOrder(deck.size());
        sort(deck.begin(),deck.end()); //vector<int>::iterator
        
        // for(auto x:vec)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        vector<int> res(deck.size());
        
        for(int i=0; i<deck.size(); i++)
        {
            res[vec[i]]=deck[i];
        }
        
        return res;
        //TC: O(nlogn+n+2*n)
        //SC: O(3*n)
    }
};