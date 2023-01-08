//got a very cool approach of lower , upper by solving on pen and paper
//try this problem more times
```
if(lower==upper)
{
if(i+1<n)
{
if(lower==points[i+1][0] || points[i+1][1]==points[i][1]) //this takes care when duplicates present in object points of type class vector<vector<int>>
{
continue;
}
upper=points[i+1][1];
}
count++;
}
```