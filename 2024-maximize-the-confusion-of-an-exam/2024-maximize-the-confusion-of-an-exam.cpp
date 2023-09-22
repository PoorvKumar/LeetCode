class Solution 
{
private:
    bool isValid(string& answerKey,int val,int k)
    {
        int t=0;
        int f=0;
        
        for(int i=0; i<val; i++)
        {
            if(answerKey[i]=='T')
            {
                t++;
            }
            else
            {
                f++;
            }
        }
        
        int minim=min(t,f);
        
        for(int i=val; i<answerKey.size(); i++)
        {
            if(minim<=k)
            {
                return true;
            }
            if(answerKey[i-val]=='T')
            {
                t--;
            }
            else
            {
                f--;
            }
            
            if(answerKey[i]=='T')
            {
                t++;
            }
            else
            {
                f++;
            }
            
            minim=min(t,f);
        }
        
        return minim<=k;
    }
public:
    int maxConsecutiveAnswers(string& answerKey, int k) 
    {
        int low=k;
        int high=answerKey.length();
        
        int mid=(low+high)/2;
        
        while(low<=high)
        {
            // cout<<low<<" "<<mid<<" "<<high<<endl;
            
            if(isValid(answerKey,mid,k))
            {
                // cout<<mid<<endl;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
            
            mid=(low+high)/2;
            
        }
        
        return mid;
    }
};