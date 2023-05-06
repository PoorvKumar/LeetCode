class Solution 
{
private:
    long long M=1e9+7;
    
    int numSubseqUtil(vector<int>& nums,int target,int index,map<int,int>& mp)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        
        int exclude=numSubseqUtil(nums,target,index+1,mp);
        int include=0;
        
        mp[nums[index]]++;
        int minim=(*mp.begin()).first;
        int maxim=(*mp.rbegin()).first;
        
        // cout<<minim<<" "<<maxim<<endl;
        
        if(minim+maxim<=target)
        {
            include=1+numSubseqUtil(nums,target,index+1,mp);
        }
        
        mp[nums[index]]--;
        if(mp[nums[index]]==0)
        {
            mp.erase(nums[index]);
        }
        
        return (exclude+include)%M;
    }
    
    unordered_map<int,int> umap; //umap[p]
    
    int power(int n,int p)
    {
        if(p==0)
        {
            return 1;
        }
        
        if(p==1)
        {
            return n;
        }
        
        if(umap.count(p))
        {
            return umap[p];
        }
        
        return umap[p]=p%2==0?(power(n,p/2)%M*power(n,p/2)%M)%M:(n*power(n,p/2)%M*power(n,p/2)%M)%M;
    }
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        // map<int,int> mp;
        
        // return numSubseqUtil(nums,target,0,mp);
        
        int ans=0;
        
        int i=0;
        int j=nums.size()-1;
        
        while(i<=j)
        {
            if(nums[i]+nums[j]<=target)
            {
                // ans=(ans+j-i+1)%M;
                // int val=pow(2,j-i)%M;
                umap.clear();
                int val=power(2,j-i)%M;
                ans=(ans+val)%M;
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return ans;
    }
};