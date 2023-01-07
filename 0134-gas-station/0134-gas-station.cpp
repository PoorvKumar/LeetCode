class Solution 
{
private:
    // queue<int> q;
    stack<int> q;
    int n;
    
    int canComplete(vector<int>& gas,vector<int>& cost,int index)
    {
        int i=index;
        // int initialGas=0;
        // int val=initialGas+gas[index]-cost[index];
        int val=0;
        
        do
        {
            val=val+gas[i]-cost[i];
            // val=initialGas+gas[i]-cost[i];
            i=(i+1)%n; //circular queue
            // initialGas=val;
        }
        while(val>=0 && i!=index);
        
        if(val<0)
        {
            return -1;
        }
        
        return index;
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        n=gas.size();
        
        for(int i=0; i<n; i++)
        {
            if(gas[i]>=cost[i])
            {
                q.push(i); //push possible ans index in object q of type class queue
            }
        }
        
        int index=-1;
        
        while(!q.empty())
        {
            // index=q.front();
            index=q.top();
            int ans=canComplete(gas,cost,index);
            if(ans!=-1)
            {
                return ans;
            }
            q.pop();
        }
        
        // cout<<index<<endl;
        return -1;
    }
};