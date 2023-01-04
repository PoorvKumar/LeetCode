class Solution 
{
private:
    unordered_map<int,int> umap;
    int helper(int count)
    {
        if(count<0 || count==1)
        {
            return INT_MAX;
        }
        
        if(count==0)
        {
            return 0;
        }
        
        if(!umap.count(count-3))
        {
            umap[count-3]=helper(count-3);
        }
        
        if(!umap.count(count-2))
        {
            umap[count-2]=helper(count-2);
        }
        
        umap[count]=1+min(umap[count-3],umap[count-2]);
        return umap[count];
    }
public:
    int minimumRounds(vector<int>& tasks) 
    {
        int round=0;
        
        sort(tasks.begin(),tasks.end()); //O(nlogn)
        // for(auto x:tasks)
        // {
        //     cout<<x<<" ";
        // }
        
        int i=0;
        int diff=tasks[0];
        int n=tasks.size();
        
        int count=0;
        
        while(i<n)
        {
            diff=tasks[i];
            count=0;
            
            while(i<n && diff==tasks[i])
            {
                i++;
                count++;
            }
            
            int x=helper(count);
            if(x==INT_MAX)
            {
                return -1;
            }
            
            round=round+x;
        }
        
        return round;
    }
};