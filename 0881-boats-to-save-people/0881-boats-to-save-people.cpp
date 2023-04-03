class Solution 
{
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(),people.end());
        
        //Two Pointers Approach
        int i=0;
        int j=people.size()-1;
        
        int ans=0;
        
        while(i<j)
        {
            if(people[i]+people[j]<=limit)
            {
                ans++;
                i++;
                j--;
            }
            else
            {
                ans++;
                j--;
            }
        }
        
        if(i==j)
        {
            ans++;
        }
        
        return ans;
    }
};