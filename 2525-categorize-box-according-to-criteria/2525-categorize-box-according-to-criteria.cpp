class Solution 
{
public:
    string categorizeBox(int length, int width, int height, int mass) 
    {
        unsigned long long int x=(long long)length*(long long)width*(long long)height;
        bool bulky=x>=1000000000 || length>=10000 || width>=10000 || height>=10000;
        // bool bulky=x>=1e9 || length>=1e4 || width>=1e4 || height>=1e4;
        bool heavy=mass>=100;
        
        if(bulky && heavy)
        {
            return "Both";
        }
        
        if(bulky)
        {
            return "Bulky";
        }
        if(heavy)
        {
            return "Heavy";
        }
        
        return "Neither";
    }
};