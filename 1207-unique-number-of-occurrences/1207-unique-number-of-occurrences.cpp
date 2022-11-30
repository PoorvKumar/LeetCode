class Solution 
{
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        
        // for(int i=0; i<arr.size(); i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        
        unordered_set<int> uset;
        
        for(int i=0; i<arr.size(); i++)
        {
            int x=i;
            int p=arr[i];
            while(x<arr.size() && p==arr[x])
            {
                x++;
            }
            x=x-i;
            // cout<<x<<endl;
            if(uset.count(x)==1)
            {
                return false;
            }
            uset.insert(x);
            i=i+x-1;
        }
        
        return true;
    }
};