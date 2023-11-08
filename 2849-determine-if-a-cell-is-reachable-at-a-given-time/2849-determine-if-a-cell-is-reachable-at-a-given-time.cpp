class Solution 
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
        if(fx==sx && fy==sy)
        {
            return t==0 || t>1;
        }
        
        if(fx==sx || fy==sy)
        {
            if(fx==sx)
            {
                return abs(fy-sy)<=t;
            }
            
            return abs(fx-sx)<=t;
        }
        
        int diffX=abs(fx-sx);
        int diffY=abs(fy-sy);
        
        if(diffX+diffY<=t)
        {
            return true;
        }
        
        int tx=t-diffX;
        
        if(tx<0)
        {
            return false;
        }
        
        if(tx>diffY)
        {
            return false;
        }
        
        if(tx==diffY)
        {
            return true;
        }
        
        int ty=diffY-tx;
        
        if(ty>diffX)
        {
            return false;
        }
        
        return true;
        
//         int ty=diffY-tx;
        
        
        
//         if(diffY-(t-diffX)<0)
//         {
//             return false;
//         }
        
//         if(diffX-(diffY-(t-diffX))<0)
//         {
//             return false;
//         }
    }
};