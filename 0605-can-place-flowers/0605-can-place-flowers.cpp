class Solution 
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        unordered_set<int> uset; //unmarked indices
        for(int i=0; i<flowerbed.size(); i++)
        {
            uset.insert(i);
        }
        
        for(int i=0; i<flowerbed.size(); i++)
        {
            if(flowerbed[i]==1)
            {
                uset.erase(i);
                uset.erase(i-1);
                uset.erase(i+1);
            }
        }
        
        while(n--)
        {
            if(uset.empty())
            {
                return false;
            }
            
            int x=*uset.begin();
            uset.erase(x);
            uset.erase(x-1);
            uset.erase(x+1);
        }
        
        return true;
    }
};