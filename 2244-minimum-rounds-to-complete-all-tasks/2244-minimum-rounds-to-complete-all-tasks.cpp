class Solution 
{
// private:
//     unordered_map<int,int> umap;
//     int helper(int count)
//     {
//         if(count<0 || count==1)
//         {
//             return INT_MAX;
//         }
        
//         if(count==0)
//         {
//             return 0;
//         }
        
//         if(!umap.count(count-3))
//         {
//             umap[count-3]=helper(count-3);
//         }
        
//         if(!umap.count(count-2))
//         {
//             umap[count-2]=helper(count-2);
//         }
        
//         umap[count]=1+min(umap[count-3],umap[count-2]);
//         return umap[count];
//     }
public:
    int minimumRounds(vector<int>& tasks)  
    {
        unordered_map<int,int> umap;
        int round=0;
        
        for(int i=0; i<tasks.size(); i++)//O(n)
        {
            umap[tasks[i]]++;
        }      
        
        for(auto &x:umap)
        {
            // cout<<x.first<<" "<<x.second<<endl;
            if(x.second==1)
            {
                return -1;
            }
            else
            {
                round=round+(int)ceil(x.second/3.0); //ceil() function in math.h header file
            }
            
            // round=round+helper(x.second);
        }
        
        return round;
    }
};