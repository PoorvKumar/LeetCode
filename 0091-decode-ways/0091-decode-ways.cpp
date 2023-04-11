class Solution 
{
private:
    unordered_map<int,int> umap; //umap[index]
    
    int numDecodingsUtil(string& s,int index)
    {
        if(s[index]=='0') //base case
        {
            return INT_MIN;
        }
        
        if(index>=s.length()) //base case
        {
            return 1;
        }
        
        if(umap.count(index))
        {
            return umap[index];
        }
        
        int ans=0;
        
        if(index<s.length()-1)
        {
            string num=s.substr(index,2);
            int n=stoi(num);
            if(s[index+1]=='0')
            {
                if(n>26)
                {
                    return 0;
                }
                
                return numDecodingsUtil(s,index+2);
            }
            
            if(n<=26)
            {
                ans=numDecodingsUtil(s,index+2);
                if(ans<0)
                {
                    ans=0;
                }
            }
        }
        
        ans=ans+numDecodingsUtil(s,index+1);
        // return ans;
        
        return umap[index]=ans;
    }
public:
    int numDecodings(string s) 
    {
        int ans=numDecodingsUtil(s,0);
        
        return ans>=0?ans:0;
    }
};