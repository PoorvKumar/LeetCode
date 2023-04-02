class Solution 
{
private:
    int helper(vector<int>& potions,int spell,long long success)
    {
        int low=0;
        int high=potions.size();
        int mid=(low+high)/2;
        
        while(low<high)
        {
            if((long long)spell*(long long)potions[mid]>=success)
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
            mid=(low+high)/2;
        }
        
        // int count=potions.size()-low;
        return potions.size()-low; //when low==high is true then mid, when low==high is false then low 
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<int> ans(spells.size(),0);
        sort(potions.begin(),potions.end());
        
        for(int i=0; i<spells.size(); i++)
        {
            int count=0;
            // for(int j=0; j<potions.size(); j++) //Brute Force //TC: O(n^2) //SC: O(n)
            // {
            //     if((long long)spells[i]*(long long)potions[j]>=success)
            //     {
            //         count++;
            //     }
            // }
            
            count=helper(potions,spells[i],success);
            
            ans[i]=count;
        }
        
        return ans;
    }
};