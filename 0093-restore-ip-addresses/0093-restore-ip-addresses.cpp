class Solution 
{
private:
    bool isValidIP(string s)
    {
        if(s.empty() || s.length()>3 || (s[0]=='0' && s.length()>1))
        {
            return false;
        }
        // cout<<s<<endl;
        int y=stoi(s);
        
        return y<=255;
        // return y>255?false:true;
    }
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> vec;
        int n=s.length();
        
        for(int i=0; i<n-3; i++)
        {
            for(int j=i+1; j<n-2; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    string a=s.substr(0,i+1-0);
                    string b=s.substr(i+1,j-i);
                    string c=s.substr(j+1,k-j);
                    string d=s.substr(k+1,n-k);
                    
                    if(isValidIP(a) && isValidIP(b) && isValidIP(c) && isValidIP(d))
                    {
                        string str=a+'.'+b+'.'+c+'.'+d;
                        // cout<<str<<endl;
                        vec.push_back(str);
                    }
                }
            }
        }
        
        return vec;
    }
};