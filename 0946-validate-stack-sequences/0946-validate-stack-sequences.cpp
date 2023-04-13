class Solution 
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int> stk;
        
        int index1=0;
        int index2=0;
        
//         while(index1<pushed.size() && pushed[index1]!=popped[index2])
//         {
//             stk.push(pushed[index1]);
//             index1++;
//         }
        
//         if(index1>=pushed.size() && popped.size()>1)
//         {
//             return false;
//         }
        
        while(index2<popped.size())
        {
            if(stk.empty() || popped[index2]!=stk.top())
            {
                while(index1<pushed.size() && pushed[index1]!=popped[index2])
                {
                    stk.push(pushed[index1]);
                    index1++;
                }
                
                if(index1>=pushed.size())
                {
                    return false;
                }
                
                stk.push(pushed[index1++]);
            }
//             if(popped[index2]!=stk.top())
//             {
//                 while(index1<pushed.size() && pushed[index1]!=popped[index2])
//                 {
//                     stk.push(pushed[index1]);
//                     index1++;
//                 }
                
//                 if(index1>=pushed.size())
//                 {
//                     return false;
//                 }
                
//                 stk.push(pushed[index1++]);
//             }
            stk.pop();
            index2++;
        }
        
        return true;
    }
};