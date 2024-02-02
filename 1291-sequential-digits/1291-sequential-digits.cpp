class Solution 
{
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int> res;
        
        int lowLength=to_string(low).length();
        int highLength=to_string(high).length();
        
        // long long val=1;
        // long long curr=1;
        // for(int i=1; i<lowLength; i++)
        // {
        //     val=val*10+1;
        //     curr=curr*10+i+1;
        // }
        
        for(int i=lowLength; i<=highLength; i++)
        {
            long long val=1;
            long long curr=1;
            for(int j=1; j<i; j++)
            {
                val=val*10+1;
                curr=curr*10+j+1;
            }
            long long rangeHigh=0;
            for(int j=9-i+1; j<=9; j++)
            {
                rangeHigh=rangeHigh*10+j;
            }
            
            for(int k=1; k<9; k++)
            {
                if(curr>rangeHigh)
                {
                    break;
                }
                if(curr>=low && curr<=high)
                {
                    res.push_back(curr);
                }
                else if(curr>high)
                {
                    return res;
                }
                
                curr=curr+val;
            }
        }
        
        return res;
    }
};

// 1 2 3 4 5 6 7 8 9 -> 1, 8
// 12 23 34 45 56 67 78 89 -> 2, 8
// 123 234 345 456 567 678 789 -> 3, 7
// 1234 2345 3456 4567 5678 6789 -> 4, 6
