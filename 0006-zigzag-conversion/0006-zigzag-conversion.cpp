class Solution {
public:
    string convert(string s, int numRows) 
    {
        //one approach can be to declare numRows objects of type class string and str.push_back(s[i]) in zig-zag fashion
        //| 1 | 2 3 | 4 | 3 2 | 1 |  2 3 | 4 | 3 2
        //for every even iteration run forward
        //for every odd iteration run backward
        //for both iterations str.pop_back() to remove last added so no doubles added
        
        if(numRows==1)
        {
            return s;
        }
        
        vector<string> vec;
        vec.assign(numRows,"");
        
        // vector<string> vec(numRows);
        
        int i=0;
        vec[0].push_back(s[0]);
        bool flag=true;
        
        while(i<s.length())
        {
            if(flag)
            {
                vec[0].pop_back();
                for(int j=0; j<numRows; j++)
                {
                    vec[j].push_back(s[i]);
                    i++;
                    if(i>=s.length())
                    {
                        break;
                    }
                }
                flag=false;
                // i--;
            }
            else
            {
                vec[numRows-1].pop_back();
                for(int j=numRows-1; j>=0; j--)
                {
                    vec[j].push_back(s[i]);
                    i++;
                    if(i>=s.length())
                    {
                        break;
                    }
                }
                flag=true;
                // i--;
            }
            if(i>=s.length())
            {
                break;
            }
            i--;
        }
        
        // for(auto x:vec)
        // {
        //     cout<<x<<" "<<x.size()<<endl;
        // }
        
        string ans;
        for(int i=0; i<vec.size(); i++)
        {
            ans=ans+vec[i];
        }
        
        return ans;        
    }
};