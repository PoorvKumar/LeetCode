//tried many approaches in begining but got TLE
//implemented my own double linked list data structure, but errors
//saw the related topics for hint
​
//makke sure to read any documentation given with problem which might help in solving the problem
​
**//got accepted solution when used set pairs but now showing TLE again
//getting this because of network and browser but still needs to be optimised**
​
//instead of defining my own linked list
//we can store objects of type class iterator in object of type class unordered_map->
```
unordered_map<int,pair<int,list<int>::iterator>> lru;
```
​
//**this way we can use erase() and fin() functions in O(1) time complexity
by passing an object of type class iterator**
​