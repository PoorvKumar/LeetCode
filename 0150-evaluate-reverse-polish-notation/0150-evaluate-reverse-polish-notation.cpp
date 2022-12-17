class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<long long int> stk;
        // string op="+-*/";
        unordered_set<string> op;
        op={"+","-","*","/"};
        
        for(int i=0; i<tokens.size(); i++)
        {
            if(op.count(tokens[i]))
            {
                char oper=tokens[i][0];
                long long int a=stk.top();
                stk.pop();
                long long int b=stk.top();
                stk.pop();
                
                switch(oper)
                {
                    case '+': 
                        stk.push(b+a);
                        break;
                    case '-':
                        stk.push(b-a);
                        break;
                    case '*':
                        stk.push(b*a);
                        break;
                    case '/':
                        stk.push(b/a);
                        break;
                    default:
                        break;
                        
                }
            }
            else
            {
                long long int x=stoi(tokens[i]);
                // cout<<x<<endl;
                stk.push(x);
            }
        }
        
        return stk.top();
    }
};