class Solution 
{
private:
    unordered_map<int,unordered_map<int,unordered_map<int,double>>> umap;
    
    double knightProbabilityUtil(int n,int k,int row,int column)
    {
        if(row<0 || row>n-1 || column<0 || column>n-1)
        {
            return 0;
        }
        
        if(k==0)
        {
            return 1;
        }
        
        if(umap.count(k) && umap[k].count(row) && umap[k][row].count(column))
        {
            return umap[k][row][column];
        }
        
        double val=knightProbabilityUtil(n,k-1,row-2,column-1);
        
        val=val+knightProbabilityUtil(n,k-1,row-2,column+1);
        
        val=val+knightProbabilityUtil(n,k-1,row-1,column-2);
        
        val=val+knightProbabilityUtil(n,k-1,row-1,column+2);
        
        val=val+knightProbabilityUtil(n,k-1,row+1,column-2);
        
        val=val+knightProbabilityUtil(n,k-1,row+1,column+2);
        
        val=val+knightProbabilityUtil(n,k-1,row+2,column-1);
        
        val=val+knightProbabilityUtil(n,k-1,row+2,column+1);
        
        double res=val/(8*1.0);
        
        // return res; //Recursive Solution
        //TC: O(8^(n*n)) //as for every row for every column 8 Recursion calls
        //SC: O(k)auxiliary stack space/depth of recursion
        
        return umap[k][row][column]=res;
    }
public:
    double knightProbability(int n, int k, int row, int column) 
    {
        return knightProbabilityUtil(n,k,row,column);
    }
};