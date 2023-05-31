class Solution 
{
public:
    string predictPartyVictory(string senate) 
    {
        int dire=0;
        int radiant=0;
        
        for(auto x:senate)
        {
            if(x=='D')
            {
                dire++;
            }
            else
            {
                radiant++;
            }
        }
        
        int n=senate.size();
        int i=0;
        
        while(true)
        {
            if(dire==0 || radiant==0)
            {
                return dire==0?"Radiant":"Dire";
            }
            
            if(senate[i]=='_')
            {
                i=(i+1)%n;
                continue;
            }
            
            if(senate[i]=='D')
            {
                int index=(i+1)%n;
                while(index!=i)
                {
                    if(senate[index]=='R')
                    {
                        senate[index]='_';
                        radiant--;
                        break;
                    }
                    index=(index+1)%n;
                }
            }
            
            if(senate[i]=='R')
            {
                int index=(i+1)%n;
                while(index!=i)
                {
                    if(senate[index]=='D')
                    {
                        senate[index]='_';
                        dire--;
                        break;
                    }
                    index=(index+1)%n;
                }
            }
            
            i=(i+1)%n;
        }
        
        return "";
    }
};