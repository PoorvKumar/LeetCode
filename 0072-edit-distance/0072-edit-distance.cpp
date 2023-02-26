class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap;
    
    int minDistanceUtil(string& str1,string& str2,int i,int j)
    {
        if(i<0 || j<0) //base case
        {
            if(i<0)
            {
                return j+1; //add j+1 characters to object s1 of type class string
            }
            return i+1; //delete i+1 characters form object s1 of type class string 
        }
        
        if(str1[i]==str2[j])
        {
            return 0+minDistanceUtil(str1,str2,i-1,j-1); //no operation performed
        }
        
        if(umap.count(i) && umap[i].count(j))
        {
            return umap[i][j];
        }
        
//         //Recursive Solution
//         int x=1+minDistanceUtil(str1,str2,i,j-1); //insert
//         int y=1+minDistanceUtil(str1,str2,i-1,j); //delete
//         int z=1+minDistanceUtil(str1,str2,i-1,j-1); //replace
        
        int x=0,y=0,z=0;
        x=umap[i][j-1]=minDistanceUtil(str1,str2,i,j-1); //insert
        y=umap[i-1][j]=minDistanceUtil(str1,str2,i-1,j); //delete
        z=umap[i-1][j-1]=minDistanceUtil(str1,str2,i-1,j-1); //replace
        
        int ans=min(x,y);
        ans=min(ans,z);
        
//         return ans;
        
        umap[i][j]=1+ans;
        
        return umap[i][j];
    }
public:
    int minDistance(string word1, string word2)
    {
        return minDistanceUtil(word1,word2,word1.length()-1,word2.length()-1);
    }
};