class Solution 
{
private:
    unordered_map<int,int> umap;
public:
    int fib(int n) 
    {
        if(n<2)
        {
            return n;
        }
        
        // return fib(n-1)+fib(n-2);
        
        if(!umap.count(n-1))
        {
            umap[n-1]=fib(n-1);
        }
        if(!umap.count(n-2))
        {
            umap[n-2]=fib(n-2);
        }
        
        return umap[n]=umap[n-1]+umap[n-2];
    }
};