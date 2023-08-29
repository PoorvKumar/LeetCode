class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        int maxim=0;
        
        for(int i=0; i<n; i++)
        {
            maxim=max(maxim,height[i]);
            left[i]=maxim;
        }
        
        maxim=0;
        for(int i=n-1; i>=0; i--)
        {
            maxim=max(maxim,height[i]);
            right[i]=maxim;
        }
        
        int ans=0;
        
        for(int i=1; i<n-1; i++)
        {
            int h=min(left[i],right[i]);
            
            // if(h>=height[i])
            // {
            //     cout<<h-height[i]<<endl;
            //     ans=ans+h-height[i];
            // }
            
            ans=ans+h-height[i];
        }
        
        return ans;
    }
};

// stack<pair<int,int>> stk;
        
// //NGE towards right //right bound
// stk.push({height[0],0});

// for(int i=1; i<n; i++)
// {
//     while(!stk.empty() && stk.top().first<=height[i])
//     {
//         right[stk.top().second]=height[i];
//         stk.pop();
//     }
//     stk.push({height[i],i});
// }

// while(!stk.empty())
// {
//     stk.pop();
// }

// //NGE towards left //left bound
// stk.push({height[n-1],n-1});

// for(int i=n-2; i>=0; i--)
// {
//     while(!stk.empty() && stk.top().first<=height[i])
//     {
//         left[stk.top().second]=height[i];
//         stk.pop();
//     }
//     stk.push({height[i],i});
// }