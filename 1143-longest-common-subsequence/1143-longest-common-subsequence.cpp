class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[index1][index2]
    
    int longestCommonUtil(string& text1,string& text2,int index1,int index2)
    {
        if(index1>=text1.length() || index2>=text2.length())
        {
            return 0;
        }
        
        if(umap.count(index1) && umap[index1].count(index2))
        {
            return umap[index1][index2];
        }
        
        if(text1[index1]==text2[index2])
        {
            return umap[index1][index2]=1+longestCommonUtil(text1,text2,index1+1,index2+1);
        }
        
        int t1=longestCommonUtil(text1,text2,index1+1,index2);
        int t2=longestCommonUtil(text1,text2,index1,index2+1);
        
        // return max(t1,t2);
        
        return umap[index1][index2]=max(t1,t2);
    }
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        return longestCommonUtil(text1,text2,0,0);
    }
};