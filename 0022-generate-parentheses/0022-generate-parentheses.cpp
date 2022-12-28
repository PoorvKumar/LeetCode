class Solution 
{
private:
    void helper(int l,int r,string& str,vector<string>& vec)
    {
        if(l==0 && r==0)
        {
            if(str[str.length()-1]!='(')
            {
                vec.push_back(str);
            }
            return;
        }
        
        if(l!=0)
        {
            str=str+'(';
            helper(l-1,r,str,vec);
            str.pop_back();
        }
        
        if(r!=0 && l<=r-1) //so that after adding new r>=l true for balanced parenthesis
        {
            str=str+')';
            helper(l,r-1,str,vec);
            str.pop_back();
        }
        
        return ;
    }
public:
    vector<string> generateParenthesis(int n) 
    {
        int l=n-1;
        int r=n;
        string str="(";
        vector<string> res;
        
        helper(l,r,str,res);
        
        return res;
    }
};