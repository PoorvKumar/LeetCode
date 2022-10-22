class Solution {
public:
    string intToRoman(int num)
    {
        string s;
        string str;
        
        int n=to_string(num).size();
        
        while(n<4)
        {
            // str=str+'0';
            str+='0';
            n++;
        }
        str=str+to_string(num);
        
        int a=str[0]-'0';
        // cout<<str;
        
        for(int i=0; i<4; i++)
        {
            a=str[i]-'0';
            if(a==4 || a==9)
            {
                if(a==4)
                {
                    switch(i)
                    {
                        case 1:
                            s=s+"CD";
                            break;
                        case 2:
                            s=s+"XL";
                            break;
                        case 3:
                            s=s+"IV";
                            break;
                    }
                }
                else
                {
                    switch(i)
                    {
                        case 1:
                            s=s+"CM";
                            break;
                        case 2:
                            s=s+"XC";
                            break;
                        case 3:
                            s+="IX";
                            break;
                    }
                }
            }
            else if(a<5)
            {
                while(a--)
                {
                    switch(i)
                    {
                        case 0:
                            s=s+'M';
                            break;
                        case 1:
                            s+='C';
                            break;
                        case 2:
                            s+='X';
                            break;
                        case 3:
                            s=s+'I';
                            break;
                    }
                }
            }
            else
            {
                switch(i)
                {
                    case 1:
                        s=s+'D';
                        break;
                    case 2:
                        s=s+'L';
                        break;
                    case 3:
                        s=s+'V';
                        break;
                }
                a=a-5;
                while(a--)
                {
                    switch(i)
                    {
                        case 1:
                            s=s+'C';
                            break;
                        case 2:
                            s=s+'X';
                            break;
                        case 3:
                            s=s+'I';
                            break;
                    }
                }
            }
        }
        
        return s;
    }
};