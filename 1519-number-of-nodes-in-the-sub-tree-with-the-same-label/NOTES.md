//right now the problem is parent not getting right
//we can see that first index in every adjacency list is the parent of the node
​
//now got TLE
​
```
if(adjList[src].size()==1)
{
//then it must be leaf node, can be root also but to avoid added -1 in its adjacency list as its parent
//whenever stuck perform DRY RUN
}
```
```
//optimised very much but still getting TLE
//before passed object countHash of type class vector by referenmmce which gave wrong answer when same character in different subtrees
//now again passed by refernce but with prevCount subtracted
//problem was not passing object labels of type class string by reference because of which for every function call memory was allocated for object labels of type class string and it was assigned the string in object labes of type class string
//so other approaches should also work with this
```