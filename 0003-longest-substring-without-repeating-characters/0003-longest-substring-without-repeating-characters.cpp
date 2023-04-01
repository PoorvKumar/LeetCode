class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int> umap;
        int ans=0;
        int low=0;
        
        for(int i=0; i<s.length(); i++)
        {
            if(umap.count(s[i]) && umap[s[i]]>=low) //char present in substring after low
            {
                ans=max(ans,i-low);
                low=umap[s[i]]+1;
                // umap[s[i]]=i;
            }
            // else
            // {
            //     umap[s[i]]=i;
            // }
            umap[s[i]]=i;
        }
        
        int n=s.length();
        ans=max(ans,n-low); //when i becomes equal to n
        
        return ans; //Two pointers Approach -> Optimised 
        //TC: O(n)
        //SC: O(n)
    }
};

// class Solution 
// {
// public:
//     int lengthOfLongestSubstring(string s) 
//     {
//         int ans=0;
//         int left=0;
//         int right=0;
//         unordered_set<char> uset;
        
//         while(right<s.length())
//         {
//             if(uset.count(s[right]))
//             {
//                 while(left<right)
//                 {
//                     uset.erase(s[left]);
//                     if(s[left]==s[right])
//                     {
//                         left++;
//                         break;
//                     }
//                     left++;
//                 }
//             }
//             uset.insert(s[right]);
//             ans=max(ans,right-left+1);
//             right++;
//         }
        
//         return ans; //Two Pointers Approach
//         //TC: O(2*n) //as O(n) for left O(n) for right
//         //SC: O(n)
//     }
// };