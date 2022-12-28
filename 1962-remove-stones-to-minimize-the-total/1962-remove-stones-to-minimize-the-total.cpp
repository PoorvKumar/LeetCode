class Solution 
{
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        int sum=accumulate(piles.begin(),piles.end(),0); //[beginAddress,endAddress),initialSum
        
        // multiset<int> s_piles(piles.begin(),piles.end());
        //we can also use object of type class priority_queue for max heap data structure
        priority_queue<int> s_piles(piles.begin(),piles.end());
        
        while(k--)
        {
            // int x=*s_piles.rbegin();
            int x=s_piles.top();
            
            // cout<<x<<endl;
            
            sum=sum-x;
            // s_piles.erase(s_piles.find(x));
            s_piles.pop();
            
            x=x-x/2;
            sum=sum+x;
            // s_piles.insert(x);
            s_piles.push(x);
        }
        
        return sum;
    }
};