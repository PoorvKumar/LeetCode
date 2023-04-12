class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> stk;
        
        string s=path;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='/') //remove multiple forward slashes
            {
                int j=i+1;
                while(j<s.length() && s[j]=='/')
                {
                    j++;
                }
                i=j-1;
                continue;
            }
            
            int j=i+1;
            while(j<s.length() && s[j]!='/')
            {
                j++;
            }
            
            string str=s.substr(i,j-i);
            
            i=j-1;
            
            if(str.compare("..")==0) //move one directory up
            {
                if(!stk.empty())
                {
                    stk.pop();
                }
                continue;
            }
            
            if(str.compare(".")!=0) //push directory to stack
            {
                stk.push(str);
            }
        }
        
        stack<string> stk1;
        
        while(!stk.empty())
        {
            stk1.push(stk.top());
            stk.pop();
        }
        
        path="/";
        while(!stk1.empty()) //reverse the stack
        {
            path=path+stk1.top();
            path=path+'/';
            stk1.pop();
        }
        
        if(path.length()>1 && path.back()=='/')
        {
            path.pop_back();
        }
        
        return path;
    }
};


//remove double forward slashes all forward slashes may have consecutive forward slash more than 2
//using stack user-defined ADT data structure
//if(stk.empty())
// {
//     stk.push("/");
// }

//loop through path string 
//while(i<s.length() && s[i]!='/')
// {
//     i++;
// }
//if(str.compare("..")==0)
// {
//     stk.pop();
// }
//if(str.compare(".")!=0)
// {
//     stk.push(str);
// }

// stack<string> stk1;



// string ans="";
// while(!stk1.empty())
// {
//     ans=ans+stk1.top();
//     stk1.pop();
// }
// if(ans.length()>1 && ans.back()=='/')
// {
//     ans.pop_back();
// }

// return ans;

