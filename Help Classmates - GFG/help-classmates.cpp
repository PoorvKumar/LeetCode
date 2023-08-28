//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> help_classmate(vector<int> arr, int n) 
    {
        // for(int i=0; i<arr.size()-1; i++)
        // {
        //     int nse=arr[i];
        //     int j=i+1;
            
        //     while(j<arr.size() && arr[j]>=arr[i])
        //     {
        //         j++;
        //     }
            
        //     if(j>=arr.size())
        //     {
        //         arr[i]=-1;
        //         continue;
        //     }
            
        //     arr[i]=arr[j];
        // }
        
        // arr.back()=-1;
        
        // return arr;
        
        stack<pair<int,int>> stk;
        
        stk.push({arr[0],0});
        
        for(int i=1; i<arr.size(); i++)
        {
            if(stk.top().first>arr[i])
            {
                arr[stk.top().second]=arr[i];
                stk.pop();
            }
            
            while(!stk.empty() && stk.top().first>arr[i])
            {
                arr[stk.top().second]=arr[i];
                stk.pop();
            }
            
            stk.push({arr[i],i});
        }
        
        while(!stk.empty())
        {
            arr[stk.top().second]=-1;
            stk.pop();
        }
        
        return arr;
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends