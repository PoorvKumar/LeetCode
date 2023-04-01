class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int ans=0;
        int left=0;
        int right=0;
        unordered_set<char> uset;
        
        while(right<s.length())
        {
            if(uset.count(s[right]))
            {
                while(left<right)
                {
                    uset.erase(s[left]);
                    if(s[left]==s[right])
                    {
                        left++;
                        break;
                    }
                    left++;
                }
            }
            uset.insert(s[right]);
            ans=max(ans,right-left+1);
            right++;
        }
        
        return ans; //Two Pointers Approach
        //TC: O(2*n) //as O(n) for left O(n) for right
        //SC: O(n)
    }
};

// class Solution 
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int ans=0;
//         int low=0;
//         unordered_map<char,int> umap;
        
//         if(s.length()==1)
//         {
//             return 1;
//         }
        
//         for(int i=0; i<s.length(); i++)
//         {
//             if(umap.count(s[i]) && umap[s[i]]!=-1)
//             {
//                 ans=max(ans,i-low);
//                 low=umap[s[i]]+1; //previous+1
//                 umap[s[i]]=i; //current
//                 for(auto &x:umap)
//                 {
//                     if(x.second<low)
//                     {
//                         x.second=-1;
//                     }
//                 }
//             }
//             else
//             {
//                 umap[s[i]]=i;
//             }
//         }
        
//         int n=s.length(); //does not work when s.length() instead of n 
//         ans=max(ans,n-low); //incase of no repeating characters
        
//         return ans; //TC: O(n^2) optmising Brute Force
//     }
// };