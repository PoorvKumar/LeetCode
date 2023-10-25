class Solution 
{
private:
    int kthGrammarUtil(int n,int k)
    {
        if(n==1)
        {
            return 0;
        }
        
        // int prevk=k/2;
        int val=kthGrammarUtil(n-1,k/2);
        
        if(val==0)
        {
            if(k%2==0)
            {
                return 0;
            }
            return 1;
        }
        
        if(k%2==0)
        {
            return 1;
        }
        return 0;
    }
public:
    int kthGrammar(int n, int k) 
    {
        return kthGrammarUtil(n,k-1);
    }
};