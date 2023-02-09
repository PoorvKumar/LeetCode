class Solution 
{
// private:
//     class TrieNode
//     {
//     public:
//         vector<TrieNode*> child;
//         bool flag=false; //inClass initializer
        
//         TrieNode()
//         {
//             child.assign(26,NULL);
//             flag=false;
//         }
        
//         // TrieNode(char c)
//         // {
//         //     child[c-'a']=new TrieNode();
//         //     flag=false;
//         // }
//     };
    
//     TrieNode* root;
//     unordered_map<string,bool> umap;
    
//     TrieNode* insertNode(string& s)
//     {
//         // TrieNode* p=new TrieNode(s[index]);
//         TrieNode* p=root;
//         int i=0;
        
//         while(i<s.length())
//         {
//             if(p->child[s[i]-'a']==NULL)
//             {
//                 p->child[s[i]-'a']=new TrieNode();
//             }
//             // p->child[s[i]-'a']=new TrieNode();
//             p=p->child[s[i]-'a'];
//             i++;
//         }
        
//         p->flag=true;
        
//         return root;
//     }
    
//     bool isPresent(string& s)
//     {
//         if(umap.count(s))
//         {
//             return umap[s];
//         }
//         TrieNode* p=root;
//         int i=0;
        
//         while(i<s.length())
//         {
//             if(p->child[s[i]-'a']!=NULL)
//             {
//                 p=p->child[s[i]-'a'];
//             }
//             else
//             {
//                 return false;
//             }
//             i++;
//         }
        
//         umap[s]=p->flag;
//         return p->flag;
//     }
public:
    long long distinctNames(vector<string>& ideas)
    {
//         //trie
//         root=new TrieNode();
        
//         for(auto x:ideas)
//         {
//             root=insertNode(x);
//         }
        
        long long ans=0;
        
//         for(int i=0; i<ideas.size(); i++)
//         {
//             for(int j=i+1; j<ideas.size(); j++)
//             {
//                 string s1=ideas[i];
//                 string s2=ideas[j];
//                 if(s1[0]==s2[0])
//                 {
//                     continue;
//                 }
                
//                 char c=s1[0]; //character swap
//                 s1[0]=s2[0];
//                 s2[0]=c;
                
//                 if(!isPresent(s1) && !isPresent(s2))
//                 {
//                     // cout<<s1<<" "<<s2<<endl;
//                     ans=ans+2;
//                 }
//             }
//         }
        
//         // string str="tonuts";
//         // cout<<isPresent(str);
        
//         return ans;
        
         //tried solving by Implemenmting my own Trie data structure
        //bot got TLE 74 / 89 testdcases passed
        //saw better solution in discuss section
        
        vector<unordered_set<string>> vec(26);
        
        for(auto x:ideas)
        {
            vec[x[0]-'a'].insert(x.substr(1)); //x.substr(1,x.length()-1);
            //all sttarting with same letter grouped together
        }
        
        for(int i=0; i<26; i++)
        {
            for(int j=i+1; j<26; j++)
            {
                int count=0;
                for(auto x:vec[j])
                {
                    if(vec[i].count(x)==1) //if same substring present count increment
                    {
                        count++;
                    }
                }
                ans=ans+(vec[j].size()-count)*(vec[i].size()-count);
            }
        }
        
        ans=ans*2;
        
        return ans;
    }
};