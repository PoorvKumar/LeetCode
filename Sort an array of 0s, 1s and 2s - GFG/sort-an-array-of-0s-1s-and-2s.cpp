//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        int x0=0;
        int x1=0;
        int x2=0;
        
        for(int i=0; i<n; i++)
        {
            if(arr[i]==0)
            {
                x0++;
            }
            if(arr[i]==1)
            {
                x1++;
            }
            if(arr[i]==2)
            {
                x2++;
            }
        }
        
        int i=0;
        
        while(x0--)
        {
            arr[i++]=0;
        }
        while(x1--)
        {
            arr[i++]=1;
        }
        while(x2--)
        {
            arr[i++]=2;
        }
        
        return;
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends