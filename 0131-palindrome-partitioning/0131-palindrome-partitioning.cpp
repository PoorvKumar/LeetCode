class Solution 
{
private:
    // vector<vector<string>> res;
    // int n;
    
    bool isPalindrome(string& s)
    {
        int i=0;
        int j=s.length()-1;
        
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
    
    vector<vector<string>> partitionHelper(string s)
    {
        vector<vector<string>> vec;
        if(s.size()==1)
        {
            // if(s.length()==n)
            // {
            //     return vec;
            // }
            vec.push_back({s});
            return vec;
        }
        
        for(int i=0; i<s.length(); i++)
        {
            string str=s.substr(0,i+1);
            if(isPalindrome(str))
            {
                vector<vector<string>> ans=partitionHelper(s.substr(i+1,s.length()-i-1));
                for(auto x:ans)
                {
                    vec.push_back({str});
                    for(auto y:x)
                    {
                        vec[vec.size()-1].push_back(y);
                    }
                }
            }
        }
        
        if(!s.empty() && isPalindrome(s))
        {
            vec.push_back({s});
        }
        
        return vec;
    }
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> vec;
        if(s.size()==1)
        {
            vec.push_back({s});
            return vec;
        }
        
        // n=s.length();
        
        vec=partitionHelper(s);
        
        // if(isPalindrome(s))
        // {
        //     vec.push_back({s});
        // }
        
        return vec;

//         for(int i=0; i<s.length(); i++)
//         {
//             string str=s.substr(0,i+1);
//             if(isPalindrome(str))
//             {
//                 vector<vector<string>> ans=partitionHelper(s.substr(i+1,s.length()-i-1));
//                 // vector<vector<string>> ans=partition(s.substr(i+1,s.length()-i-1));
//                 for(auto x:ans)
//                 {
//                     vec.push_back({str});
//                     for(auto y:x)
//                     {
//                         vec[vec.size()-1].push_back(y);
//                     }
//                 }
//             }
//         }

//         return vec;
    }
};