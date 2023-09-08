class Solution 
{
public:
    int characterReplacement(string s, int k) 
    {
        int ans=0;
        int left=0;

        vector<int> freq(26,0);

        for(int i=0; i<s.length(); i++)
        {
            freq[s[i]-'A']++;
            int maxim=0;
            for(int j=0; j<26; j++)
            {
                maxim=max(maxim,freq[j]);
            }

            int rem=i+1-left-maxim;

            if(rem<=k)
            {
                ans=max(ans,i+1-left);
            }
            else
            {
                freq[s[left]-'A']--;
                left++;
            }
        }   

        return ans;
    }
};