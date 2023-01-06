class Solution 
{
// private:
//     unordered_map<int,unordered_map<int,int>> umap;
    
//     int maxIceCreamUtil(vector<int>& costs, int coins,int index=0)
//     {
//         if(coins<0)
//         {
//             return INT_MIN;
//         }
        
//         if(coins==0 || index>costs.size()-1)
//         {
//             return 0;
//         }
        
//         if(!umap.count(coins-costs[index]) && !umap[coins-costs[index]].count(index+1))
//         {
//             umap[coins-costs[index]][index+1]=maxIceCreamUtil(costs,coins-costs[index],index+1);
//         }
        
//         if(!umap.count(coins) && !umap[coins].count(index+1))
//         {
//             umap[coins][index+1]=maxIceCreamUtil(costs,coins,index+1);
//         }
        
//         // return max(1+maxIceCream(costs,coins-costs[index],index+1),maxIceCream(costs,coins,index+1)); //Recursive Relation
        
//         return umap[coins][index]=max(1+umap[coins-costs[index]][index+1],umap[coins][index+1]);
//     }
    
public:
    int maxIceCream(vector<int>& costs,int coins)
    {
        sort(costs.begin(),costs.end()); //O(nlogn)
        // if(costs[0]>coins)
        // {
        //     return 0;
        // }
        
        // return maxIceCreamUtil(costs,coins,0);
        
        int count=0;
        
        for(int i=0; i<costs.size(); i++)
        {
            if(costs[i]>coins)
            {
                return count;
            }
            
            coins=coins-costs[i];
            count++;
        }
//         int i=0;
        
//         while(i<costs.size() && coins>0)
//         {
//             if(costs[i]>coins) //very good approach
//             {
//                 return count;
//             }
//             coins=coins-costs[i];
//             i++;
//             count++;
//         }
        
        return count;
    }
};