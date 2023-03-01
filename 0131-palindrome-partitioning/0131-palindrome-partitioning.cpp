class Solution 
{
private:
    vector<vector<string>> res;
    vector<string> vec;
    
    bool isPalindrome(string& s,int index,int n)
    {
        int i=index;
        int j=index+n-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    void partitionUtil(string& s,int index,int n)
    {
        if(index+n==s.length())
        {
            if(isPalindrome(s,index,n))
            {
                vec.push_back(s.substr(index,n));
                res.push_back(vec);
                vec.pop_back();
            }
            
            return ;
        }
        
        if(isPalindrome(s,index,n))
        {
            vec.push_back(s.substr(index,n));
            partitionUtil(s,index+n,1);
            vec.pop_back();
        }
        
        partitionUtil(s,index,n+1);
        
        return ;
    }
public:
    vector<vector<string>> partition(string s)
    {
        partitionUtil(s,0,1);
        
        return res;
    }
};