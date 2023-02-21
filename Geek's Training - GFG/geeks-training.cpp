//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
public:
    int maximumPoints(vector<vector<int>>& points, int n)
    {
        for(int i=n-2; i>=0; i--) //Bottom-Up DP approach -> Tabulation
        {
            for(int j=0; j<3; j++)
            {
                int x=0;
                for(int k=0; k<3; k++)
                {
                    if(j!=k)
                    {
                        x=max(x,points[i+1][k]);
                    }
                }
                points[i][j]=points[i][j]+x;
            }
        }
        
        int ans=-1;
        for(int i=0; i<3; i++)
        {
            ans=max(ans,points[0][i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends