class Solution 
{
private:
    unordered_map<int,int> umap;
public:
    int tribonacci(int n) 
    {
        if(n<=0)
        {
            return 0;
        }
        if(n<3)
        {
            return 1;
        }
        
        if(!umap.count(n-1))
        {
            umap[n-1]=tribonacci(n-1);
        }
        if(!umap.count(n-2))
        {
            umap[n-2]=tribonacci(n-2);
        }
        if(!umap.count(n-3))
        {
            umap[n-3]=tribonacci(n-3);
        }
        
        // return tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
        umap[n]=umap[n-3]+umap[n-2]+umap[n-1];
        return umap[n];
    }
};