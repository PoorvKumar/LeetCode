class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits,int i=1,int flag=0) 
    {
        if(flag==1)
        {
            if(i<=digits.size()) 
            {
                if(digits[digits.size()-i]==9) //value 9 at index when 1 carry
                {
                    digits[digits.size()-i]=0;
                    return plusOne(digits,i+1,1);
                }
                digits[digits.size()-i]++; //value incremented if not 9 at index and 1 carry
                return digits;
            }
            digits.insert(digits.begin(),1); //adding 1 of carry in the end
            return digits;
        }
        
        if(i<=digits.size() && digits[digits.size()-i]==9)
        {
            digits[digits.size()-i]=0;
            return plusOne(digits,i+1,1);
        }
        
        if(i==1)
        {
            int n=digits.size()-i;
            digits[n]++;
            return digits;
        }
        
        return digits;
    }
};