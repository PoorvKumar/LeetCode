class Solution 
{
private:
    vector<string> res;
    
    void fullJustifyUtil(vector<string>& words,int maxWidth,int index)
    {
        if(index>=words.size())
        {
            return ;
        }
        
        int i=index;
        int sum=0;
        int n=0;
        
        while(i<words.size() && maxWidth-sum>=n-1)
        {
            sum=sum+words[i].length();
            n++;
            i++;
            
            if(maxWidth-sum<n-1)
            {
                sum=sum-words[i-1].length();
                n--;
                i--;
                break;
            }
        }
        
        if(n==1 || i>=words.size())
        {
            string str="";
            
            for(int k=index; k<index+n; k++)
            {
                str+=words[k];
                if(str.length()==maxWidth)
                {
                    break;
                }
                
                str+=" ";
            }
            
            int l=maxWidth-str.length();
            // while(l--)
            // {
            //     str+=" ";
            // }
            // cout<<l<<endl;
            str.append(l,' ');
            
            res.push_back(str);
            
            fullJustifyUtil(words,maxWidth,index+n);
            return ;
        }
        
        int spl=maxWidth-sum;
        string sp="";
        int l=spl/(n-1);
        // cout<<maxWidth<<" "<<sum<<" "<<spl<<" "<<n-1<<endl;
        // while(l--)
        // {
        //     sp+=" ";
        // }
        sp.append(l,' ');
        
        int rem=spl%(n-1);
        
        string str="";
        
        for(int k=index; k<index+n; k++)
        {
            str+=words[k];
            if(str.length()==maxWidth)
            {
                break;
            }
            
            str+=sp;
            
            if(rem)
            {
                str+=" ";
                rem--;
            }
        }
        
        res.push_back(str);
        
        fullJustifyUtil(words,maxWidth,i);
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        fullJustifyUtil(words,maxWidth,0);
        
        return res;
    }
};