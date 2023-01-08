class Solution 
{
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if(points.size()==1)
        {
            return 1;
        }
        
        sort(points.begin(),points.end()); //O(nlogn)
        int count=0;
        
        int n=points.size();
        int lower=points[0][0];
        int upper=points[0][1];
        
        for(int i=0; i<n; i++)
        {
            if(points[i][0]>upper)
            {
                count++;
                lower=points[i][0];
                upper=points[i][1];
                continue;
            }
            
            if(points[i][0]<=upper && points[i][0]>=lower)
            {
                lower=points[i][0];
            }
            if(points[i][1]<upper)
            {
                upper=points[i][1];
            }
            
            if(lower==upper)
            {
                // count++; //important to increment count later
                if(i+1<n)
                {
                    if(lower==points[i+1][0] || points[i+1][1]==points[i][1])
                    {
                        continue;
                    }
                    // lower=points[i+1][0];
                    upper=points[i+1][1];
                    // cout<<upper<<endl;
                }
                count++;
                continue;
            }
            // lower=points[i][0]>lower?points[i][0]:lower;
            // upper=points[i][1]<upper?points[i][1]:upper;
        }
        
        // bool flag=points[n-1][1]==points[n-2][1] && points[n-1][0]==points[n-2][0];
        // if(flag && n>2) //last two same
        // {
        //     count--;
        // }
        // return ++count;
        return lower==upper?count:count+1;
    }
};