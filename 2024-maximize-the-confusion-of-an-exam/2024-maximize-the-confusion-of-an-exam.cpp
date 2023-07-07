class Solution 
{
private:
    bool isValid(string& answerKey,int windowSize,int k)
    {
        unordered_map<char,int> umap;
        
        for(int i=0; i<windowSize; i++)
        {
            umap[answerKey[i]]++;
        }
        
        if(min(umap['T'],umap['F'])<=k)
        {
            return true;
        }
        
        for(int i=windowSize; i<answerKey.length(); i++)
        {
            umap[answerKey[i]]++;
            umap[answerKey[i-windowSize]]--;
            
            if(min(umap['T'],umap['F'])<=k)
            {
                return true;
            }
        }
        
        return false;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        int low=k;
        int high=answerKey.length();
        
        while(low<high)
        {
            int mid=(low+high+1)/2;
            if(isValid(answerKey,mid,k))
            {
                low=mid;
            }
            else
            {
                high=mid-1;
            }
        }
        
        return low;
    }
};