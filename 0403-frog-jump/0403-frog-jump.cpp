class Solution 
{
private:
    vector<bool> stone;
    
    unordered_map<int,unordered_map<int,bool>> umap;
    
    bool canCrossUtil(int index,int k)
    {
        if(index>=stone.size()-1)
        {
            return index==stone.size()-1;
        }
        
        if(umap.count(index) && umap[index].count(k))
        {
            return umap[index][k];
        }
        
        if(!stone[index])
        {
            return false;
        }
        
        if(k-1>0 && canCrossUtil(index+k-1,k-1))
        {
            return true;
        }
        
        if(canCrossUtil(index+k,k))
        {
            return true;
        }
        
        if(canCrossUtil(index+k+1,k+1))
        {
            return true;
        }
        
        // return false;
        
        return umap[index][k]=false;
    }
public:
    bool canCross(vector<int>& stones) 
    {
        if(stones.back()==INT_MAX)
        {
            return false;
        }
        
        int n=stones.back()+1;
        stone.assign(n,false);
        
        for(int i=0; i<stones.size(); i++)
        {
            stone[stones[i]]=true;
        }
        
        if(!stone[1])
        {
            return false;
        }
        
        return canCrossUtil(1,1);
    }
};