class Solution 
{
private:
    unordered_map<char,vector<string>> umap;
    
    vector<string> letterCombinationUtil(string& digits,int index)
    {
        if(index==digits.size()-1)
        {
            return umap[digits[index]];
        }
        
        vector<string> vec=letterCombinationUtil(digits,index+1);
        
        vector<string> res;
        
        for(auto s:umap[digits[index]])
        {
            for(auto str:vec)
            {
                res.push_back(s+str);
            }
        }
        
        return res;
    }
public:
    vector<string> letterCombinations(string digits) 
    {
        if(digits.empty())
        {
            return vector<string>();
        }
        
        umap['2']={"a","b","c"};
        umap['3']=vector<string>({"d","e","f"});
        umap['4']={"g","h","i"};
        umap['5']=vector<string>({"j","k","l"});
        umap['6']={"m","n","o"};
        umap['7']=vector<string>({"p","q","r","s"});
        umap['8']={"t","u","v"};
        umap['9']={"w","x","y","z"};
        
        return letterCombinationUtil(digits,0);
    }
};