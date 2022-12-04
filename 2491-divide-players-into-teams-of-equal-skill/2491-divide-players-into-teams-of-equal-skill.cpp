class Solution {
public:
    long long dividePlayers(vector<int>& skill) 
    {
        sort(skill.begin(),skill.end());
        
        int n=skill.size();
        int totalSkill=skill[0]+skill[n-1];
        
        long long int chemistry=0;
        chemistry=skill[0]*skill[n-1];
        int j=n-2;
        
        for(int i=1; i<j; i++)
        {
            if(skill[i]+skill[j]!=totalSkill)
            {
                return -1;
            }
            chemistry=chemistry+skill[i]*skill[j];
            j--;
            // cout<<chemistry<<endl;
        }
        
        return chemistry;
    }
};